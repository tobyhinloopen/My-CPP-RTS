#import "catch.h"
#import "unit_damage_manager.h"
#import "template_component.h"

TEST_CASE("unit_damage_manager") {
  component_template volatile_thing_template;
  volatile_thing_template.health = 5;
  volatile_thing_template.volatility = 10;

  auto volatile_thing = std::make_shared<template_component>(volatile_thing_template);

  component_template though_thing_template;
  though_thing_template.health = 25;
  though_thing_template.volatility = 0;

  auto though_thing = std::make_shared<template_component>(though_thing_template);

  auto components = std::make_shared<component_set>();
  components->push_back(volatile_thing);
  components->push_back(though_thing);

  unit_damage_manager unit_damage_manager(components);

  REQUIRE(volatile_thing->health() == 5);
  REQUIRE(though_thing->health() == 25);

  SECTION("Applying minor damage to each component") {
    damage_report report = unit_damage_manager.apply_damage(8);

    REQUIRE(volatile_thing->health() == 1);
    REQUIRE(though_thing->health() == 21);
    REQUIRE(report.damage_applied == 8);
    REQUIRE(report.volatility_triggered == 0);
  }

  SECTION("Applying damage just enough to trigger volatility") {
    damage_report report = unit_damage_manager.apply_damage(10);

    REQUIRE(report.damage_applied == 20);
    REQUIRE(report.volatility_triggered == 10);
    REQUIRE(volatile_thing->dead() == true);
    REQUIRE(though_thing->health() == 10);
  }

  SECTION("The remainder-damage applies to the healthiest component") {
    damage_report report = unit_damage_manager.apply_damage(1);

    REQUIRE(report.damage_applied == 1);
    REQUIRE(report.volatility_triggered == 0);
    REQUIRE(volatile_thing->health() == 5);
    REQUIRE(though_thing->health() == 24);
  }
}
