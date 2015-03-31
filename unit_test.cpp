#import "catch.h"
#import "unit.h"
#import "unit_template.h"
#import "component_template.h"

TEST_CASE("Unit") {
  ComponentTemplate volatile_thing;
  volatile_thing.health = 5;
  volatile_thing.volatility = 10;

  ComponentTemplate thougher_thing;
  thougher_thing.health = 25;
  thougher_thing.volatility = 0;

  UnitTemplate unit_template;
  unit_template.add(volatile_thing);
  unit_template.add(thougher_thing);

  Unit unit(unit_template);

  REQUIRE(unit.health() == 30);

  SECTION("Applying minor damage") {
    unit.apply_damage(8);
    REQUIRE(unit.health() == 22);
  }

  SECTION("Applying damage just enough to trigger volatility") {
    unit.apply_damage(10);
    REQUIRE(unit.health() == 10);
  }

  // SECTION("Applying minor damage (not divisible by number of components)") {
  //   unit.apply_damage(1);
  //   REQUIRE(unit.health() == 29);
  // }
}
