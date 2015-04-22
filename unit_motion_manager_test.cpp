#import "catch.h"
#import "unit_motion_manager.h"
#import "fixture_component.h"

TEST_CASE("UnitMotionManager") {
  auto components = std::make_shared<ComponentSet>();
  UnitMotionManager unit_motion_manager(components);

  REQUIRE(unit_motion_manager.force().none());
  REQUIRE(unit_motion_manager.velocity().none());

  SECTION("Having a component with force") {
    auto force_component = std::make_shared<FixtureComponent>(0);
    force_component->force(Force(1, 2));
    components->push_back(force_component);

    REQUIRE(unit_motion_manager.force().any());
    REQUIRE(unit_motion_manager.force().x == 1);
    REQUIRE(unit_motion_manager.force().y == 2);

    REQUIRE(unit_motion_manager.velocity().none());
    REQUIRE(unit_motion_manager.velocity().x == 0);
    REQUIRE(unit_motion_manager.velocity().y == 0);

    unit_motion_manager.update();

    REQUIRE(unit_motion_manager.velocity().any());
    REQUIRE(unit_motion_manager.velocity().x == 1);
    REQUIRE(unit_motion_manager.velocity().y == 2);

    unit_motion_manager.update();

    REQUIRE(unit_motion_manager.velocity().any());
    REQUIRE(unit_motion_manager.velocity().x == 2);
    REQUIRE(unit_motion_manager.velocity().y == 4);
  }

  // "Air" resistance should be added by adding a force which grows linearly with the velocity.
  // For example, for every 1 speed, resistance force is -1. This way, when a component emits a
  // constant force of 10, the unit motion manager reaches a top speed of 10. When resistance force
  // is decreased, the top spead increases.

  // All math is exact in our simulation. In motion-related calculations, we need to set fixed data
  // points with integer math (starting point, end point) and approximate in-between state.
}
