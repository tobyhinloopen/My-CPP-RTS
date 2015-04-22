#import "unit_motion_manager.h"

UnitMotionManager::UnitMotionManager(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components) :
Componentable(components),
_velocity(Velocity(0, 0)) {
}

Force UnitMotionManager::force() const {
  Force force;
  for(const auto component : *components)
    force += component->force();
  return force;
}

Velocity UnitMotionManager::velocity() const {
  return _velocity;
}

void UnitMotionManager::update() {
  Force current_force = force();
  _velocity.x += current_force.x;
  _velocity.y += current_force.y;
}
