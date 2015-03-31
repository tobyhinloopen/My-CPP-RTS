#import "component.h"

Component::Component(ComponentTemplate component_template)
  : component_template(component_template)
  , current_health(component_template.health)
  , current_damage_applied(0)
{}

void Component::apply_damage(int damage) {
  if(damage > current_health) {
    current_damage_applied = current_health;
    current_health = 0;
  } else {
    current_damage_applied = damage;
    current_health -= damage;
  }
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

int Component::damage_applied() const {
  return current_damage_applied;
}

bool Component::alive() const {
  return health() > 0;
}

bool Component::dead() const {
  return !alive();
}
