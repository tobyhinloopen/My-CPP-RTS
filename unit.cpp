#import "unit.h"
#import "damage_report.h"
#import <iostream>

using namespace std;

int health_for_components(const shared_ptr<const vector<shared_ptr<Component>>>);

Unit::Unit(const shared_ptr<const vector<shared_ptr<Component>>> components) 
  : Componentable(components)
  , UnitDamageManager(components)
  , _initial_health(health_for_components(components))
{}

int Unit::mass() const {
  int mass = 0;
  for(const auto component : *components)
    mass += component->mass();
  return mass;
}

int Unit::initial_health() const {
  return _initial_health;
}

int Unit::health() const {
  return health_for_components(components);
}

bool Unit::alive() const {
  return health() > 0;
}

bool Unit::dead() const {
  return !alive();
}

int health_for_components(const shared_ptr<const vector<shared_ptr<Component>>> components) {
  int health = 0;
  for(const auto component : *components)
    health += component->health();
  return health;
}
