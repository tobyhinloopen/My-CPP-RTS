#import "catch.h"
#import "unit_template.h"
#import "support/component_template_factory.h"

TEST_CASE("unit_template") {
  component_template_factory component_template_factory;
  unit_template unit_template;

  REQUIRE(unit_template.complexity() == 0);
  REQUIRE(unit_template.mass() == 0);
  REQUIRE(unit_template.health() == 0);

  SECTION("with some components") {
    unit_template.add(component_template_factory.create_cannon_weapon_template());
    unit_template.add(component_template_factory.create_laser_weapon_template());
    unit_template.add(component_template_factory.create_engine_template());
    unit_template.add(component_template_factory.create_reactor_template());

    REQUIRE(unit_template.complexity() == 240);
    REQUIRE(unit_template.health() == 130);
    REQUIRE(unit_template.mass() == 200);

    auto created_components = unit_template.create_components();

    REQUIRE(created_components->size() == 4);

    int created_components_health_sum = 0;
    int created_components_mass_sum = 0;

    for(auto created_component : *created_components) {
      created_components_health_sum += created_component->health();
      created_components_mass_sum += created_component->mass();
    }

    REQUIRE(created_components_health_sum == 130);
    REQUIRE(created_components_mass_sum == 200);
  }
}
