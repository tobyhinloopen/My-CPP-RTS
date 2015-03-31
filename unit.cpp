#import "unit.h"
#import <iostream>

using namespace std;

Unit::Unit(shared_ptr<vector<shared_ptr<Component>>> components)
: components(components)
, unit_damage_manager(components)
{}

void Unit::apply_damage(int damage_remaining) {
  unit_damage_manager.apply_damage(damage_remaining);
}

int Unit::mass() const {
  int mass = 0;
  for(auto component : *components)
    mass += component->mass();
  return mass;
}

int Unit::health() const {
  int health = 0;
  for(auto component : *components)
    health += component->health();
  return health;
}

bool Unit::alive() const {
  return health() > 0;
}

bool Unit::dead() const {
  return !alive();
}
