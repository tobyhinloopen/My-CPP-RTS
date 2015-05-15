#import "component.h"

component::component(const health_t health): _health(health) {}
component::~component() {}

damage_report component::apply_damage(const damage_t damage) {
  damage_report report;
  if(alive()) {
    if(damage >= health()) {
      report.damage_applied = _health;
      report.volatility_triggered = volatility();
      _health = 0.0;
    } else {
      report.damage_applied = damage;
      _health -= damage;
    }
  }
  return report;
}

mass_t component::mass() const {
  return 0.0;
}

volatility_t component::volatility() const {
  return 0.0;
}

force_t component::force() const {
  return force_t();
}

health_t component::health() const {
  return _health;
}

bool component::alive() const {
  return health() > 0.0;
}

bool component::dead() const {
  return !alive();
}
