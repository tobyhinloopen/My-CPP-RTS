#import "unit_damage_manager.h"

using namespace std;

DamageReport damage_each_component(const shared_ptr<const vector<shared_ptr<Component>>> components, int damage);
DamageReport damage_component(Component & component, int damage);

UnitDamageManager::UnitDamageManager(const shared_ptr<const vector<shared_ptr<Component>>> components)
  : components(components)
{}

DamageReport UnitDamageManager::apply_damage(const int damage) {
  DamageReport damage_report;

  int current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return damage_report;

  if(damage > current_alive_components_count)
    damage_report += damage_each_component(components, damage / current_alive_components_count);

  current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return damage_report;

  int damage_remaining = damage - damage_report.damage_applied + damage_report.volatility_triggered;
  if(damage_remaining > current_alive_components_count)
    damage_report += apply_damage(damage_remaining);
  else if(damage_remaining > 0) {
    Component & current_healthiest_component = *healthiest_component();
    damage_report += damage_component(current_healthiest_component, 1);
    damage_remaining = damage - damage_report.damage_applied + damage_report.volatility_triggered;
    if(damage_remaining > 0)
      damage_report += apply_damage(damage_remaining);
  }
  return damage_report;
}

shared_ptr<Component> UnitDamageManager::healthiest_component() const {
  auto current_healthiest_component = *components->begin();
  for(const auto component : *components)
    if(component->health() > current_healthiest_component->health())
      current_healthiest_component = component;
  return current_healthiest_component;
}

int UnitDamageManager::alive_components_count() const {
  int alive_components_count = 0;
  for(const auto component : *components)
    if(component->alive())
      ++alive_components_count;
  return alive_components_count;
}

DamageReport damage_each_component(const shared_ptr<const vector<shared_ptr<Component>>> components, int damage) {
  DamageReport damage_report;
  for(const auto component : *components)
    damage_report += damage_component(*component, damage);
  return damage_report;
}

DamageReport damage_component(Component & component, int damage) {
  DamageReport damage_report;
  if(component.alive()) {
    component.apply_damage(damage);
    damage_report.damage_applied += component.damage_applied();
    if(component.dead())
      damage_report.volatility_triggered += component.volatility();
  }
  return damage_report;
}
