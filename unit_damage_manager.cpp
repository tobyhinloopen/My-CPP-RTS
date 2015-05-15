#import "unit_damage_manager.h"

damage_report damage_each_component(const component_set & components, const damage_t damage);

unit_damage_manager::unit_damage_manager(const std::shared_ptr<const component_set> components)
  : componentable(components)
{}

damage_report unit_damage_manager::apply_damage(const damage_t damage) {
  damage_report report;

  auto current_alive_components_count = alive_components_count();
  if(current_alive_components_count == 0)
    return report;

  report += damage_each_component(*components, damage / current_alive_components_count);

  auto remaining_damage = damage - report.damage_applied + report.volatility_triggered;
  if(remaining_damage > 0 && alive_components_count() > 0)
    report += apply_damage(damage - report.damage_applied + report.volatility_triggered);
  return report;
}

component & unit_damage_manager::healthiest_component() const {
  auto current_healthiest_component = *components->begin();
  for(const auto component : *components)
    if(component->health() > current_healthiest_component->health())
      current_healthiest_component = component;
  return *current_healthiest_component;
}

short_size_t unit_damage_manager::alive_components_count() const {
  short_size_t alive_components_count = 0;
  for(const auto component : *components)
    if(component->alive())
      ++alive_components_count;
  return alive_components_count;
}

damage_report damage_each_component(const component_set & components, const damage_t damage) {
  damage_report damage_report;
  for(const auto component : components)
    damage_report += component->apply_damage(damage);
  return damage_report;
}
