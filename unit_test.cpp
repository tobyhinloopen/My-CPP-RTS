#import "catch.h"
#import "unit.h"
#import "fixture_component.h"
#import "component.h"
#include <memory>
#include <vector>

using namespace std;

TEST_CASE("Unit") {
  auto though_component = make_shared<Component>(25);

  auto volatile_component = make_shared<FixtureComponent>(5);
  volatile_component->volatility(10);

  auto components = make_shared<vector<shared_ptr<Component>>>();
  components->push_back(volatile_component);
  components->push_back(though_component);

  Unit unit(components);

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
