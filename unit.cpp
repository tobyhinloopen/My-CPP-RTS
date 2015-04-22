#import "unit.h"

Unit::Unit(const std::shared_ptr<const ComponentSet> components):
Componentable(components),
UnitHealthManager(components),
UnitDamageManager(components) {
}

int Unit::mass() const {
  int mass = 0;
  for(const auto component : *components)
    mass += component->mass();
  return mass;
}
