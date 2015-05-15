#import "unit_health_manager.h"

unit_health_manager::unit_health_manager(const std::shared_ptr<const component_set> components):
componentable(components),
_initial_health(health()) {
}

health_t unit_health_manager::initial_health() const {
  return _initial_health;
}

health_t unit_health_manager::health() const {
  health_t health = 0;
  for(const auto component : *components)
    health += component->health();
  return health;
}

bool unit_health_manager::alive() const {
  return health() > 0;
}

bool unit_health_manager::dead() const {
  return health() == 0;
}
