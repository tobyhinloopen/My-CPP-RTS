#import "catch.h"
#import "velocity.h"

TEST_CASE("velocity_t") {
  SECTION("Default initializer") {
    velocity_t velocity;

    REQUIRE(velocity.none());
    REQUIRE(velocity.x == 0);
    REQUIRE(velocity.y == 0);
  }

  SECTION("Initializer with 2 attributes") {
    velocity_t intitializer_velocity(1, 2);

    REQUIRE(intitializer_velocity.any());
    REQUIRE(intitializer_velocity.x == 1);
    REQUIRE(intitializer_velocity.y == 2);
  }

  SECTION("With any velocity") {
    velocity_t velocity(1, 1);

    REQUIRE(!velocity.none());
    REQUIRE(velocity.any());
  }
}
