#import "catch.h"
#import "unit_motion_manager.h"
#import "component_template.h"
#import "component.h"
#import <vector>

using namespace std;

TEST_CASE("UnitMotionManager") {
  auto components = make_shared<const vector<shared_ptr<Component>>>();
  UnitMotionManager unit_motion_manager(components);

  REQUIRE(unit_motion_manager.force().none());
  REQUIRE(!unit_motion_manager.force().any());
#if 0
  SECTION("Having a component with force") {
    // TODO:
    // We must seperate Component from the ComponentTemplate and make all Component methods virtual,
    // so we can create any kind of subclass from Component, like one with constant force applied to
    // it. This way we don't need a component template every time we want to test anything requiring
    // a component.
    //
    // Here we must create a component having a constant force applied to it.
    components.push_back(/* component here */);
  }
#endif
}
