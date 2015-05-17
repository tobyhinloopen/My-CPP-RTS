#import "catch.h"
#import "unit_motion_manager.h"
#import "fixture_component.h"
#import "velocity_support.h"

TEST_CASE("unit_motion_manager") {
  auto components = std::make_shared<component_set>();
  unit_motion_manager unit_motion_manager(components);

  REQUIRE(unit_motion_manager.force().none());
  REQUIRE(unit_motion_manager.velocity().none());
  REQUIRE(unit_motion_manager.mass() == mass_t(0));

  auto mass_component = std::make_shared<fixture_component>(0);
  mass_t sample_mass(2);
  mass_component->mass(sample_mass);

  auto x_force_component = std::make_shared<fixture_component>(0);
  force_t x_force(12, 0);
  x_force_component->force(x_force);

  SECTION("Adding a component with mass") {
    components->push_back(mass_component);

    REQUIRE(unit_motion_manager.force().none());
    REQUIRE(unit_motion_manager.velocity().none());
    REQUIRE(unit_motion_manager.mass() == sample_mass);
  }

  SECTION("Adding a component with force but no mass") {
    components->push_back(x_force_component);

    REQUIRE(unit_motion_manager.force() == x_force);
    REQUIRE(unit_motion_manager.velocity().none());

    unit_motion_manager.update();

    REQUIRE(unit_motion_manager.force() == x_force);
    REQUIRE(unit_motion_manager.velocity().none());
  }

  SECTION("Adding a component with force and mass") {
    components->push_back(x_force_component);
    components->push_back(mass_component);

    REQUIRE(unit_motion_manager.force() == x_force);
    REQUIRE(unit_motion_manager.velocity().none());

    unit_motion_manager.update();

    REQUIRE(unit_motion_manager.force() == x_force);
    REQUIRE(unit_motion_manager.velocity() == velocity_t(6, 0));
  }

  // SECTION("Having a component with force") {
  //   auto force_component = std::make_shared<fixture_component>(0);
  //   force_component->mass(1);
  //   force_component->force(force_t(1, 2));
  //   components->push_back(force_component);
  //
  //   REQUIRE(unit_motion_manager.force() == force_t(1, 2));
  //   REQUIRE(unit_motion_manager.velocity().none());
  //
  //   unit_motion_manager.update();
  //   REQUIRE(unit_motion_manager.velocity() == velocity_t(1, 2));
  //
  //   unit_motion_manager.update();
  //   REQUIRE(unit_motion_manager.velocity() == velocity_t(2, 4));
  //
  //   for(int i(0); i<8; ++i)
  //     unit_motion_manager.update();
  //
  //   REQUIRE(unit_motion_manager.velocity() == velocity_t(10, 20));
  // }
  //
  // SECTION("Having a component with force with wind resistance") {
  //   auto force_component = std::make_shared<fixture_component>(0);
  //   force_component->mass(1);
  //   force_component->force(force_t(1, 0));
  //   components->push_back(force_component);
  //
  //   const force_magnitude_t velocity_resistance(0.5);
  //
  //   unit_motion_manager.update_with_velocity_resistance(velocity_resistance);
  //   REQUIRE(unit_motion_manager.velocity() == velocity_t(0.75, 0));
  //
  //   unit_motion_manager.update_with_velocity_resistance(velocity_resistance);
  //   REQUIRE(unit_motion_manager.velocity() == velocity_t(5, 0));
  // }

  // "Air" resistance should be added by adding a force which grows linearly with the velocity.
  // For example, for every 1 speed, resistance force is -1. This way, when a component emits a
  // constant force of 10, the unit motion manager reaches a top speed of 5. When resistance force
  // is decreased, the top spead increases.
}
