#import "componentable.h"
#import "velocity.h"
#import "force.h"

class UnitMotionManager : private virtual Componentable {
public:
  UnitMotionManager(const std::shared_ptr<const ComponentSet> components);
  Force force() const;
  Velocity velocity() const;
  void update();
private:
  Velocity _velocity;
};
