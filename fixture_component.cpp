#import "fixture_component.h"

fixture_component::fixture_component(const health_t health):
component(health), _mass(0.0), _volatility(0.0), _force() {
}

mass_t fixture_component::mass() const {
  return _mass;
}

void fixture_component::mass(const mass_t mass) {
  _mass = mass;
}

force_t fixture_component::force() const {
  return _force;
}

void fixture_component::force(const force_t force) {
  _force = force;
}

volatility_t fixture_component::volatility() const {
  return _volatility;
}

void fixture_component::volatility(const volatility_t volatility) {
  _volatility = volatility;
}
