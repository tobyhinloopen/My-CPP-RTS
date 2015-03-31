#import "unit.h"
#import <iostream>

Unit::Unit(const UnitTemplate & unit_template)
: unit_template(unit_template)
, components(unit_template.components())
// , unit_damage_manager(components)
{
}

int Unit::mass() const {
  int mass = 0;
  for(auto component = components.begin(); component != components.end(); ++component)
    mass += component->mass();
  return mass;
}

int Unit::health() const {
  int health = 0;
  for(auto component = components.begin(); component != components.end(); ++component)
    health += component->health();
  return health;
}

void Unit::apply_damage(int damage_remaining) {
  int live_components_count = 0;
  for(auto component = components.begin(); component != components.end(); ++component)
    if(component->alive())
      ++live_components_count;

  const int damage_per_component = damage_remaining / live_components_count;
  for(auto component = components.begin(); component != components.end(); ++component) {
    if(component->alive()) {
      component->apply_damage(damage_per_component);
      damage_remaining -= component->damage_applied();
      if(component->dead())
        damage_remaining += component->volatility();
    }
  }

  if(damage_remaining > components.size())
    apply_damage(damage_remaining);
}
