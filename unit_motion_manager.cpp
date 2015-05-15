#import "unit_motion_manager.h"

short velocity_after_update_with_velocity_resistance(short force, short velocity, unsigned short resistance);

UnitMotionManager::UnitMotionManager(const std::shared_ptr<const ComponentSet> components) :
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

void UnitMotionManager::update_with_velocity_resistance(unsigned short velocity_resistance) {
  Force current_force = force();
  _velocity.x = velocity_after_update_with_velocity_resistance(_velocity.x, current_force.x, velocity_resistance);
  _velocity.y = velocity_after_update_with_velocity_resistance(_velocity.y, current_force.y, velocity_resistance);
}

short velocity_after_update_with_velocity_resistance(short velocity, short force, unsigned short resistance) {
  short next_velocity_without_resistance = velocity + force;
  short average_velocity_without_resistance = (velocity + next_velocity_without_resistance) / 2;
  short absolute_resistance = average_velocity_without_resistance * resistance;
  return velocity + force - absolute_resistance;
}
