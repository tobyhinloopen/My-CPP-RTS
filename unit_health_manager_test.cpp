#import "catch.h"
#import "unit_health_manager.h"
#import "component_template.h"
#import "component.h"
#import <vector>

using namespace std;

TEST_CASE("UnitHealthManager") {
  ComponentTemplate thing_template;
  thing_template.health = 10;

  auto thing_a = make_shared<Component>(thing_template);
  auto thing_b = make_shared<Component>(thing_template);

  auto components = make_shared<vector<shared_ptr<Component>>>();
  components->push_back(thing_a);
  components->push_back(thing_b);

  UnitHealthManager unit_health_manager(components);

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
