#import "unit_motion_manager.h"

UnitMotionManager::UnitMotionManager(const shared_ptr<const vector<shared_ptr<Component>>> components) :
Componentable(components) {
}

Force UnitMotionManager::force() const {
  return Force();
}
