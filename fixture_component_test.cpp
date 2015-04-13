#import "catch.h"
#import "fixture_component.h"

TEST_CASE("FixtureComponent") {
  FixtureComponent fixture_component(10);

  REQUIRE(fixture_component.mass() == 0);
  REQUIRE(fixture_component.health() == 10);
  REQUIRE(fixture_component.volatility() == 0);
  REQUIRE(fixture_component.alive());
  REQUIRE(!fixture_component.dead());
  REQUIRE(fixture_component.force().none());

  SECTION("Assigning force") {
    Force force;
    force.x = 1;
    force.y = 2;
    fixture_component.force(force);

    REQUIRE(fixture_component.force().x == 1);
    REQUIRE(fixture_component.force().y == 2);
  }

  SECTION("Assigning mass") {
    fixture_component.mass(20);

    REQUIRE(fixture_component.mass() == 20);
  }

  SECTION("Assigning volatility") {
    fixture_component.volatility(10);

    REQUIRE(fixture_component.volatility() == 10);
  }
}
