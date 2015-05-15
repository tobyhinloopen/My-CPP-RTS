#import "componentable.h"
#import "velocity.h"
#import "force.h"

class unit_motion_manager : private virtual componentable {
public:
  unit_motion_manager(const std::shared_ptr<const component_set> components);
  force_t force() const;
  velocity_t velocity() const;
  void update();
  void update_with_velocity_resistance(unsigned short velocity_resistance);
private:
  velocity_t _velocity;
};
