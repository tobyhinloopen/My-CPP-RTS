#import "fixture_component.h"

FixtureComponent::FixtureComponent(int health):
Component(health),
current_mass(0),
current_volatility(0),
current_force(Force()) {
}

int FixtureComponent::mass() const {
  return current_mass;
}

void FixtureComponent::mass(int mass) {
  current_mass = mass;
}

Force FixtureComponent::force() const {
  return current_force;
}

void FixtureComponent::force(Force force) {
  current_force = force;
}

int FixtureComponent::volatility() const {
  return current_volatility;
}

void FixtureComponent::volatility(int volatility) {
  current_volatility = volatility;
}
