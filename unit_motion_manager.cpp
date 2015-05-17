#import "unit_motion_manager.h"

void alter_velocity_with_velocity_resistance(
  velocity_magnitude_t &, const mass_t, const force_magnitude_t, const force_magnitude_t);

unit_motion_manager::unit_motion_manager(const std::shared_ptr<const component_set> components):
componentable(components), _velocity() {
}

force_t unit_motion_manager::force() const {
  force_t force;
  for(const auto component : *components)
    force += component->force();
  return force;
}

mass_t unit_motion_manager::mass() const {
  mass_t mass = 0;
  for(const auto component : *components)
    mass += component->mass();
  return mass;
}

velocity_t unit_motion_manager::velocity() const {
  return _velocity;
}

void unit_motion_manager::update() {
  update_with_velocity_resistance(0);
}

void unit_motion_manager::update_with_velocity_resistance(const force_magnitude_t velocity_resistance) {
  const auto current_mass = mass();
  if(current_mass == 0) return;
  const auto current_force = force();
  alter_velocity_with_velocity_resistance(
    _velocity.x, current_mass, current_force.x, velocity_resistance);
  alter_velocity_with_velocity_resistance(
    _velocity.y, current_mass, current_force.y, velocity_resistance);
}

void alter_velocity_with_velocity_resistance(
velocity_magnitude_t & velocity,
const mass_t mass,
const force_magnitude_t force,
const force_magnitude_t resistance) {
  velocity += force / mass;
}
