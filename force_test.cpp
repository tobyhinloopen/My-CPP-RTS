#import "catch.h"
#import "force.h"

TEST_CASE("Force") {
  Force force;

  REQUIRE(force.none());
  REQUIRE(force.x == 0);
  REQUIRE(force.y == 0);

  SECTION("With any force") {
    force.x = 1;
    force.y = 1;

    REQUIRE(!force.none());
    REQUIRE(force.any());
  }

  SECTION("Adding forces") {
    Force force2;
    force2.x = 10;

    force.x = 10;
    force.y = 10;
    force += force2;

    REQUIRE(force.x == 20);
    REQUIRE(force.y == 10);
  }
}
