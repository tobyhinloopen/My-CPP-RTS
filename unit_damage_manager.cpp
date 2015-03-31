#import "unit_damage_manager.h"

using namespace std;

UnitDamageManager::UnitDamageManager(shared_ptr<vector<shared_ptr<Component>>> components)
: components(components) {
}

void UnitDamageManager::apply_damage(int damage) {
  int current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return;

  damage_each_applied_damage = 0;
  damage_each_volatile_damage_triggered = 0;

  if(damage > current_alive_components_count)
    apply_damage_each(damage / current_alive_components_count);

  current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return;

  int damage_remaining = damage - damage_each_applied_damage + damage_each_volatile_damage_triggered;
  if(damage_remaining > current_alive_components_count)
    apply_damage(damage_remaining);
  else if(damage_remaining > 0) {
    Component & current_healthiest_component = *healthiest_component();
    damage_component(current_healthiest_component, 1);
    damage_remaining = damage - damage_each_applied_damage + damage_each_volatile_damage_triggered;
    if(damage_remaining > 0)
      apply_damage(damage_remaining);
  }
}

void UnitDamageManager::apply_damage_each(int damage) {
  for(auto component : *components)
    damage_component(*component, damage);
}

void UnitDamageManager::damage_component(Component & component, int damage) {
  if(component.alive()) {
    component.apply_damage(damage);
    damage_each_applied_damage += component.damage_applied();
    if(component.dead())
      damage_each_volatile_damage_triggered += component.volatility();
  }
}

shared_ptr<Component> UnitDamageManager::healthiest_component() {
  auto current_healthiest_component = *components->begin();
  for(auto component = components->begin()++; component != components->end(); ++component)
    if((*component)->health() > current_healthiest_component->health())
      current_healthiest_component = *component;
  return current_healthiest_component;
}

int UnitDamageManager::alive_components_count() {
  int alive_components_count = 0;
  for(auto component = components->begin(); component != components->end(); ++component)
    if((*component)->alive())
      ++alive_components_count;
  return alive_components_count;
}
