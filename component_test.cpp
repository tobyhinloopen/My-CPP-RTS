#import "catch.h"
#import "component.h"

TEST_CASE("component") {
  component component(10);

  REQUIRE(component.mass() == 0);
  REQUIRE(component.health() == 10);
  REQUIRE(component.volatility() == 0);
  REQUIRE(component.alive());
  REQUIRE(!component.dead());
  REQUIRE(component.force().none());
}
