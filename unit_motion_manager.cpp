#import "unit_motion_manager.h"

short velocity_after_update_with_velocity_resistance(short force, short velocity, unsigned short resistance);

unit_motion_manager::unit_motion_manager(const std::shared_ptr<const component_set> components) :
componentable(components),
_velocity(velocity_t(0, 0)) {
}

force_t unit_motion_manager::force() const {
  force_t force;
  for(const auto component : *components)
    force += component->force();
  return force;
}

velocity_t unit_motion_manager::velocity() const {
  return _velocity;
}

void unit_motion_manager::update() {
  auto current_force = force();
  _velocity.x += current_force.x;
  _velocity.y += current_force.y;
}

void unit_motion_manager::update_with_velocity_resistance(unsigned short velocity_resistance) {
  auto current_force = force();
  _velocity.x = velocity_after_update_with_velocity_resistance(_velocity.x, current_force.x, velocity_resistance);
  _velocity.y = velocity_after_update_with_velocity_resistance(_velocity.y, current_force.y, velocity_resistance);
}

short velocity_after_update_with_velocity_resistance(short velocity, short force, unsigned short resistance) {
  short next_velocity_without_resistance = velocity + force;
  short average_velocity_without_resistance = (velocity + next_velocity_without_resistance) / 2;
  short absolute_resistance = average_velocity_without_resistance * resistance;
  return velocity + force - absolute_resistance;
}
