#import "componentable.h"
#import "velocity.h"
#import "force.h"
#import "types.h"

class unit_motion_manager : private virtual componentable {
public:
  unit_motion_manager(const std::shared_ptr<const component_set> components);
  force_t force() const;
  velocity_t velocity() const;
  mass_t mass() const;
  void update();
  void update_with_velocity_resistance(const force_magnitude_t velocity_resistance);
private:
  velocity_t _velocity;
};
