#import "unit_motion_manager.h"

velocity_magnitude_t velocity_after_update_with_velocity_resistance(
  const velocity_magnitude_t, const force_magnitude_t, const force_magnitude_t);

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

void unit_motion_manager::update_with_velocity_resistance(const force_magnitude_t velocity_resistance) {
  auto current_force = force();
  _velocity.x = velocity_after_update_with_velocity_resistance(_velocity.x, current_force.x, velocity_resistance);
  _velocity.y = velocity_after_update_with_velocity_resistance(_velocity.y, current_force.y, velocity_resistance);
}

velocity_magnitude_t velocity_after_update_with_velocity_resistance(const velocity_magnitude_t velocity, const force_magnitude_t force, const force_magnitude_t resistance) {
  auto next_velocity_without_resistance = velocity + force;
  auto average_velocity_without_resistance = (velocity + next_velocity_without_resistance) / 2;
  auto absolute_resistance = average_velocity_without_resistance * resistance;
  return velocity + force - absolute_resistance;
}
