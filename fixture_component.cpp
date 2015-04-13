#import "fixture_component.h"

FixtureComponent::FixtureComponent(int health): Component(health),
_mass(0), _volatility(0), _force(Force()) {
}

int FixtureComponent::mass() const {
  return _mass;
}

void FixtureComponent::mass(int mass) {
  _mass = mass;
}

Force FixtureComponent::force() const {
  return _force;
}

void FixtureComponent::force(Force force) {
  _force = force;
}

int FixtureComponent::volatility() const {
  return _volatility;
}

void FixtureComponent::volatility(int volatility) {
  _volatility = volatility;
}
