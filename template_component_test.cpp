#import "catch.h"
#import "template_component.h"
#import "support/component_template_factory.h"

TEST_CASE("template_component") {
  component_template_factory component_template_factory;
  component_template component_template = component_template_factory.create_engine_template();
  template_component template_component(component_template);

  REQUIRE(template_component.mass() == 100.0);
  REQUIRE(template_component.health() == 40.0);
  REQUIRE(template_component.volatility() == 40.0);
  REQUIRE(template_component.alive());
  REQUIRE(!template_component.dead());
  REQUIRE(template_component.force().none());

  SECTION("applying some damage") {
    damage_report report = template_component.apply_damage(10.0);

    REQUIRE(template_component.health() == 30.0);
    REQUIRE(template_component.alive());
    REQUIRE(!template_component.dead());
    REQUIRE(report.damage_applied == 10.0);
    REQUIRE(report.volatility_triggered == 0.0);
  }

  SECTION("applying fatal damage") {
    damage_report report = template_component.apply_damage(40.0);

    REQUIRE(template_component.health() == 0.0);
    REQUIRE(!template_component.alive());
    REQUIRE(template_component.dead());
    REQUIRE(report.damage_applied == 40.0);
    REQUIRE(report.volatility_triggered == 40.0);
  }

  SECTION("applying more damage than health") {
    damage_report report = template_component.apply_damage(50.0);

    REQUIRE(template_component.health() == 0.0);
    REQUIRE(!template_component.alive());
    REQUIRE(template_component.dead());
    REQUIRE(report.damage_applied == 40.0);
    REQUIRE(report.volatility_triggered == 40.0);
  }
}
