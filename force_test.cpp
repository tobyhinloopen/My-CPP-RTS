#import "catch.h"
#import "force.h"

TEST_CASE("force") {
  SECTION("Default initializer") {
    force_t force;

    REQUIRE(force.none());
    REQUIRE(force.x == 0);
    REQUIRE(force.y == 0);
  }

  SECTION("Initializer with 2 attributes") {
    force_t intitializer_force(1, 2);

    REQUIRE(intitializer_force.any());
    REQUIRE(intitializer_force.x == 1);
    REQUIRE(intitializer_force.y == 2);
  }

  SECTION("With any force") {
    force_t force(1, 1);

    REQUIRE(!force.none());
    REQUIRE(force.any());
  }

  SECTION("Adding forces") {
    force_t force_a(10, 10);
    force_t force_b(10, 0);
    force_a += force_b;

    REQUIRE(force_a.x == 20);
    REQUIRE(force_a.y == 10);
  }
}
