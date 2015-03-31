#import "catch.h"
#import "unit_template.h"
#import "support/component_template_factory.h"

TEST_CASE("UnitTemplate") {
  ComponentTemplateFactory component_template_factory;
  UnitTemplate unit_template;

  REQUIRE(unit_template.complexity() == 0);
  REQUIRE(unit_template.mass() == 0);
  REQUIRE(unit_template.health() == 0);

  SECTION("with some components") {
    unit_template.add(component_template_factory.create_cannon_weapon_template());
    unit_template.add(component_template_factory.create_laser_weapon_template());
    unit_template.add(component_template_factory.create_engine_template());
    unit_template.add(component_template_factory.create_reactor_template());

    REQUIRE(unit_template.complexity() == 240);
    REQUIRE(unit_template.mass() == 200);
    REQUIRE(unit_template.health() == 130);
    REQUIRE(unit_template.components()->size() == 4);
  }
}
