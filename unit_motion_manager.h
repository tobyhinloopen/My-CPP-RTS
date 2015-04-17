#import "componentable.h"
#import "component.h"
#import "velocity.h"
#import "force.h"
#import <vector>
#import <memory>

class UnitMotionManager : private virtual Componentable {
public:
  UnitMotionManager(const shared_ptr<const vector<shared_ptr<Component>>> components);
  Force force() const;
  Velocity velocity() const;
  void update();
private:
  Velocity _velocity;
};
