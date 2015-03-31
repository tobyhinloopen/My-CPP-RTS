#import "catch.h"
#import "component.h"
#import "component_template.h"
#import "support/component_template_factory.h"

TEST_CASE("Component") {
  ComponentTemplateFactory component_template_factory;
  ComponentTemplate component_template = component_template_factory.create_engine_template();
  Component component(component_template);

  REQUIRE(component.mass() == 100);
  REQUIRE(component.health() == 40);
  REQUIRE(component.volatility() == 40);
  REQUIRE(component.alive());
  REQUIRE(!component.dead());

  SECTION("applying some damage") {
    component.apply_damage(10);

    REQUIRE(component.health() == 30);
    REQUIRE(component.alive());
    REQUIRE(!component.dead());
  }

  SECTION("applying fatal damage") {
    component.apply_damage(40);

    REQUIRE(component.health() == 0);
    REQUIRE(!component.alive());
    REQUIRE(component.dead());
  }

  SECTION("applying more damage than health") {
    component.apply_damage(50);

    REQUIRE(component.health() == 0);
    REQUIRE(!component.alive());
    REQUIRE(component.dead());
  }
}
