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
    DamageReport damage_report = component.apply_damage(10);

    REQUIRE(component.health() == 30);
    REQUIRE(component.alive());
    REQUIRE(!component.dead());
    REQUIRE(damage_report.damage_applied == 10);
    REQUIRE(damage_report.volatility_triggered == 0);
  }

  SECTION("applying fatal damage") {
    DamageReport damage_report = component.apply_damage(40);

    REQUIRE(component.health() == 0);
    REQUIRE(!component.alive());
    REQUIRE(component.dead());
    REQUIRE(damage_report.damage_applied == 40);
    REQUIRE(damage_report.volatility_triggered == 40);
  }

  SECTION("applying more damage than health") {
    DamageReport damage_report = component.apply_damage(50);

    REQUIRE(component.health() == 0);
    REQUIRE(!component.alive());
    REQUIRE(component.dead());
    REQUIRE(damage_report.damage_applied == 40);
    REQUIRE(damage_report.volatility_triggered == 40);
  }
}
