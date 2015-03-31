#import "unit_template.h"
#import "unit_damage_manager.h"
#import "component.h"
#import <vector>

class Unit {
public:
  Unit(const UnitTemplate &);
  int health() const;
  int mass() const;
  void apply_damage(int damage);
private:
  const UnitTemplate & unit_template;
  // const UnitDamageManager unit_damage_manager;
  std::vector<Component> components;
};
