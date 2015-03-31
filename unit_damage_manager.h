#import "component.h"
#import <vector>

class UnitDamageManager {
public:
  UnitDamageManager(const std::vector<Component*> components);
  void apply_damage(int damage);
private:
  void apply_damage_each(int damage);
  void damage_component(Component & component, const int damage);
  Component * healthiest_component();
  int alive_components_count();
  int damage_each_applied_damage;
  int damage_each_volatile_damage_triggered;
  const std::vector<Component*> components;
};
