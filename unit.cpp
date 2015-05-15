#import "unit.h"

unit::unit(const std::shared_ptr<const component_set> components):
componentable(components),
unit_health_manager(components),
unit_damage_manager(components) {
}

double unit::mass() const {
  double mass = 0.0;
  for(const auto component : *components)
    mass += component->mass();
  return mass;
}
