#import "catch.h"
#import "force.h"

TEST_CASE("force") {
  SECTION("Default initializer") {
    force_t force;

    REQUIRE(force.none());
    REQUIRE(force.x == 0.0);
    REQUIRE(force.y == 0.0);
  }

  SECTION("Initializer with 2 attributes") {
    force_t intitializer_force(1.0, 2.0);

    REQUIRE(intitializer_force.any());
    REQUIRE(intitializer_force.x == 1.0);
    REQUIRE(intitializer_force.y == 2.0);
  }

  SECTION("With any force") {
    force_t force(1.0, 1.0);

    REQUIRE(!force.none());
    REQUIRE(force.any());
  }

  SECTION("Adding forces") {
    force_t force_a(10.0, 10.0);
    force_t force_b(10.0, 0.0);
    force_a += force_b;

    REQUIRE(force_a.x == 20.0);
    REQUIRE(force_a.y == 10.0);
  }
}
