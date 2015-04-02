#import "unit.h"
#import "damage_report.h"
#import <iostream>

using namespace std;

int health_for_components(const shared_ptr<const vector<shared_ptr<Component>>>);

Unit::Unit(const shared_ptr<const vector<shared_ptr<Component>>> components):
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
