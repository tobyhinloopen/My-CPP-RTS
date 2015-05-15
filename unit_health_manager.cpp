#import "unit_health_manager.h"

unit_health_manager::unit_health_manager(const std::shared_ptr<const component_set> components):
componentable(components),
_initial_health(health_for_components(components)) {
}

double unit_health_manager::initial_health() const {
  return _initial_health;
}

double unit_health_manager::health() const {
  return health_for_components(components);
}

bool unit_health_manager::alive() const {
  return health() > 0.0;
}

bool unit_health_manager::dead() const {
  return health() == 0.0;
}

double unit_health_manager::health_for_components(const std::shared_ptr<const component_set> components) {
  double health = 0.0;
  for(const auto component : *components)
    health += component->health();
  return health;
}
