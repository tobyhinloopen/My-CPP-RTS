#import "componentable.h"
#import "velocity.h"
#import "force.h"

class UnitMotionManager : private virtual Componentable {
public:
  UnitMotionManager(const std::shared_ptr<const ComponentSet> components);
  Force force() const;
  Velocity velocity() const;
  void update();
  void update_with_velocity_resistance(unsigned short velocity_resistance);
private:
  Velocity _velocity;
};
