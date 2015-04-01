#import "component.h"
#import <iostream>

using namespace std;

Component::Component(ComponentTemplate component_template)
  : component_template(component_template)
  , current_health(component_template.health)
{}

DamageReport Component::apply_damage(int damage) {
  DamageReport damage_report;
  if(alive()) {
    if(damage >= current_health) {
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
  return component_template.mass;
}

int Component::volatility() const {
  return component_template.volatility;
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
