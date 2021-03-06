#import "catch.h"
#import "unit.h"
#import "fixture_component.h"

TEST_CASE("unit") {
  auto though_component = std::make_shared<component>(25);

  auto volatile_component = std::make_shared<fixture_component>(5);
  volatile_component->volatility(10);

  auto components = std::make_shared<component_set>();
  components->push_back(volatile_component);
  components->push_back(though_component);

  unit unit(components);

  REQUIRE(unit.health() == 30);
  REQUIRE(unit.initial_health() == 30);
  REQUIRE(unit.alive());
  REQUIRE(!unit.dead());

  SECTION("Applying minor damage") {
    unit.apply_damage(8);
    REQUIRE(unit.health() == 22);
    REQUIRE(unit.alive());
    REQUIRE(!unit.dead());
    REQUIRE(unit.initial_health() == 30);
  }

  SECTION("Applying major damage") {
    unit.apply_damage(100);
    REQUIRE(unit.health() == 0);
    REQUIRE(!unit.alive());
    REQUIRE(unit.dead());
    REQUIRE(unit.initial_health() == 30);
  }
}
