#import "unit_damage_manager.h"

damage_report damage_each_component(const component_set & components, const double damage);

unit_damage_manager::unit_damage_manager(const std::shared_ptr<const component_set> components)
  : componentable(components)
{}

damage_report unit_damage_manager::apply_damage(const double damage) {
  damage_report report;

  int current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return report;

  if(damage > current_alive_components_count)
    report += damage_each_component(*components, damage / current_alive_components_count);

  current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return report;

  int damage_remaining = damage - report.damage_applied + report.volatility_triggered;
  if(damage_remaining && damage_remaining < current_alive_components_count) {
    report += healthiest_component().apply_damage(1.0);
    damage_remaining = damage - report.damage_applied + report.volatility_triggered;
  }
  if(damage_remaining)
    report += apply_damage(damage_remaining);
  return report;
}

component & unit_damage_manager::healthiest_component() const {
  auto current_healthiest_component = *components->begin();
  for(const auto component : *components)
    if(component->health() > current_healthiest_component->health())
      current_healthiest_component = component;
  return *current_healthiest_component;
}

int unit_damage_manager::alive_components_count() const {
  int alive_components_count = 0;
  for(const auto component : *components)
    if(component->alive())
      ++alive_components_count;
  return alive_components_count;
}

damage_report damage_each_component(const component_set & components, const double damage) {
  damage_report damage_report;
  for(const auto component : components)
    damage_report += component->apply_damage(damage);
  return damage_report;
}
