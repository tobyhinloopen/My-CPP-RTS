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

  Unit unit(unit_template.components());

  REQUIRE(unit.health() == 30);
  REQUIRE(unit.initial_health() == 30);
  REQUIRE(unit.alive());
  REQUIRE(!unit.dead());

  SECTION("Applying minor damage") {
    DamageReport damage_report = unit.apply_damage(8);
    REQUIRE(unit.health() == 22);
    REQUIRE(unit.alive());
    REQUIRE(!unit.dead());
    REQUIRE(unit.initial_health() == 30);
    REQUIRE(damage_report.damage_applied == 8);
    REQUIRE(damage_report.volatility_triggered == 0);
  }

  SECTION("Applying damage just enough to trigger volatility") {
    DamageReport damage_report = unit.apply_damage(10);
    REQUIRE(unit.health() == 10);
    REQUIRE(damage_report.damage_applied == 20);
    REQUIRE(damage_report.volatility_triggered == 10);
  }

  SECTION("Applying minor damage (not divisible by number of components)") {
    DamageReport damage_report = unit.apply_damage(1);
    REQUIRE(unit.health() == 29);
    REQUIRE(damage_report.damage_applied == 1);
    REQUIRE(damage_report.volatility_triggered == 0);
  }

  SECTION("Applying major damage") {
    DamageReport damage_report = unit.apply_damage(100);
    REQUIRE(unit.health() == 0);
    REQUIRE(!unit.alive());
    REQUIRE(unit.dead());
    REQUIRE(damage_report.damage_applied == 30);
    REQUIRE(damage_report.volatility_triggered == 10);
  }
}
