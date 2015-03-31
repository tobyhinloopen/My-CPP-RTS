#import "catch.h"
#import "unit_damage_manager.h"
#import "component_template.h"
#import "damage_report.h"
#import "component.h"
#import <vector>

using namespace std;

TEST_CASE("UnitDamageManager") {
  ComponentTemplate volatile_thing_template;
  volatile_thing_template.health = 5;
  volatile_thing_template.volatility = 10;

  auto volatile_thing = make_shared<Component>(volatile_thing_template);

  ComponentTemplate though_thing_template;
  though_thing_template.health = 25;
  though_thing_template.volatility = 0;

  auto though_thing = make_shared<Component>(though_thing_template);

  auto components = make_shared<vector<shared_ptr<Component>>>();
  components->push_back(volatile_thing);
  components->push_back(though_thing);

  UnitDamageManager unit_damage_manager(components);

  REQUIRE(volatile_thing->health() == 5);
  REQUIRE(though_thing->health() == 25);

  SECTION("Applying minor damage to each component") {
    DamageReport damage_report = unit_damage_manager.apply_damage(8);

    REQUIRE(volatile_thing->health() == 1);
    REQUIRE(though_thing->health() == 21);
    REQUIRE(damage_report.damage_applied == 8);
    REQUIRE(damage_report.volatility_triggered == 0);
  }

  SECTION("Applying damage just enough to trigger volatility") {
    DamageReport damage_report = unit_damage_manager.apply_damage(10);

    REQUIRE(damage_report.damage_applied == 20);
    REQUIRE(damage_report.volatility_triggered == 10);
    REQUIRE(volatile_thing->dead() == true);
    REQUIRE(though_thing->health() == 10);
  }

  SECTION("The remainder-damage applies to the healthiest component") {
    DamageReport damage_report = unit_damage_manager.apply_damage(1);

    REQUIRE(damage_report.damage_applied == 1);
    REQUIRE(damage_report.volatility_triggered == 0);
    REQUIRE(volatile_thing->health() == 5);
    REQUIRE(though_thing->health() == 24);
  }
}
