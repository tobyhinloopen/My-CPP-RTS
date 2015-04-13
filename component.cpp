#import "component.h"
#import <iostream>

using namespace std;

Component::Component(int health):
current_health(health) {
}

Component::~Component() {
}

DamageReport Component::apply_damage(int damage) {
  DamageReport damage_report;
  if(alive()) {
    if(damage >= health()) {
      damage_report.damage_applied = current_health;
      damage_report.volatility_triggered = volatility();
      current_health = 0;
    } else {
      damage_report.damage_applied = damage;
      current_health -= damage;
    }
  }
  return damage_report;
}

int Component::mass() const {
  return 0;
}

int Component::volatility() const {
  return 0;
}

Force Component::force() const {
  return Force();
}

int Component::health() const {
  return current_health;
}

bool Component::alive() const {
  return health() > 0;
}

bool Component::dead() const {
  return !alive();
}
