#import "componentable.h"
#import "component.h"
#import "component_set.h"
#import "velocity.h"
#import "force.h"
#import <vector>
#import <memory>

class UnitMotionManager : private virtual Componentable {
public:
  UnitMotionManager(const std::shared_ptr<const ComponentSet> components);
  Force force() const;
  Velocity velocity() const;
  void update();
private:
  Velocity _velocity;
};
