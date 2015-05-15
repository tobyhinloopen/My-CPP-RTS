#import "catch.h"
#import "unit_health_manager.h"
#import "template_component.h"

TEST_CASE("unit_health_manager") {
  component_template thing_template;
  thing_template.health = 10;

  auto thing_a = std::make_shared<template_component>(thing_template);
  auto thing_b = std::make_shared<template_component>(thing_template);

  auto components = std::make_shared<component_set>();
  components->push_back(thing_a);
  components->push_back(thing_b);

  unit_health_manager unit_health_manager(components);

  REQUIRE(thing_a->health() == 10);
  REQUIRE(thing_b->health() == 10);
  REQUIRE(unit_health_manager.health() == 20);
  REQUIRE(unit_health_manager.alive());
  REQUIRE(!unit_health_manager.dead());
  REQUIRE(unit_health_manager.initial_health() == 20);

  SECTION("With all components set to 0 health") {
    thing_a->apply_damage(10);
    thing_b->apply_damage(10);
    REQUIRE(thing_a->health() == 0);
    REQUIRE(thing_b->health() == 0);
    REQUIRE(unit_health_manager.health() == 0);
    REQUIRE(!unit_health_manager.alive());
    REQUIRE(unit_health_manager.dead());
    REQUIRE(unit_health_manager.initial_health() == 20);
  }
}
