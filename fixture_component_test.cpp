#import "catch.h"
#import "fixture_component.h"

TEST_CASE("fixture_component") {
  fixture_component fixture_component(10);

  REQUIRE(fixture_component.mass() == 0);
  REQUIRE(fixture_component.health() == 10);
  REQUIRE(fixture_component.volatility() == 0);
  REQUIRE(fixture_component.alive());
  REQUIRE(!fixture_component.dead());
  REQUIRE(fixture_component.force().none());

  SECTION("Assigning force") {
    fixture_component.force(force_t(1, 2));
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
