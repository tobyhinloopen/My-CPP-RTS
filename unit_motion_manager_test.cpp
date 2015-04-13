#import "catch.h"
#import "unit_motion_manager.h"
#import "fixture_component.h"
#import <vector>

using namespace std;

TEST_CASE("UnitMotionManager") {
  auto components = make_shared<vector<shared_ptr<Component>>>();
  UnitMotionManager unit_motion_manager(components);

  REQUIRE(unit_motion_manager.force().none());

  SECTION("Having a component with force") {
    auto force_component = make_shared<FixtureComponent>(0);
    force_component->force(Force(1, 2));
    components->push_back(force_component);

    REQUIRE(unit_motion_manager.force().any());
    REQUIRE(unit_motion_manager.force().x == 1);
    REQUIRE(unit_motion_manager.force().y == 2);
  }
}
