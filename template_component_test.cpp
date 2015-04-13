#import "catch.h"
#import "component_template.h"
#import "template_component.h"
#import "support/component_template_factory.h"

TEST_CASE("TemplateComponent") {
  ComponentTemplateFactory component_template_factory;
  ComponentTemplate component_template = component_template_factory.create_engine_template();
  TemplateComponent template_component(component_template);

  REQUIRE(template_component.mass() == 100);
  REQUIRE(template_component.health() == 40);
  REQUIRE(template_component.volatility() == 40);
  REQUIRE(template_component.alive());
  REQUIRE(!template_component.dead());
  REQUIRE(template_component.force().none());

  SECTION("applying some damage") {
    DamageReport damage_report = template_component.apply_damage(10);

    REQUIRE(template_component.health() == 30);
    REQUIRE(template_component.alive());
    REQUIRE(!template_component.dead());
    REQUIRE(damage_report.damage_applied == 10);
    REQUIRE(damage_report.volatility_triggered == 0);
  }

  SECTION("applying fatal damage") {
    DamageReport damage_report = template_component.apply_damage(40);

    REQUIRE(template_component.health() == 0);
    REQUIRE(!template_component.alive());
    REQUIRE(template_component.dead());
    REQUIRE(damage_report.damage_applied == 40);
    REQUIRE(damage_report.volatility_triggered == 40);
  }

  SECTION("applying more damage than health") {
    DamageReport damage_report = template_component.apply_damage(50);

    REQUIRE(template_component.health() == 0);
    REQUIRE(!template_component.alive());
    REQUIRE(template_component.dead());
    REQUIRE(damage_report.damage_applied == 40);
    REQUIRE(damage_report.volatility_triggered == 40);
  }
}
