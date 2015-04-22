#import "unit.h"
#import "damage_report.h"
#import <iostream>

int health_for_components(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>>);

Unit::Unit(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components):
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
