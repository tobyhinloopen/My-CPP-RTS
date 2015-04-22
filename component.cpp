#import "component.h"

Component::Component(int health): _health(health) {}
Component::~Component() {}

DamageReport Component::apply_damage(int damage) {
  DamageReport damage_report;
  if(alive()) {
    if(damage >= health()) {
      damage_report.damage_applied = _health;
      damage_report.volatility_triggered = volatility();
      _health = 0;
    } else {
      damage_report.damage_applied = damage;
      _health -= damage;
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
  return _health;
}

bool Component::alive() const {
  return health() > 0;
}

bool Component::dead() const {
  return !alive();
}
