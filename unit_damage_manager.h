#import "component.h"
#import <vector>
#import <memory>

using namespace std;

class UnitDamageManager {
public:
  UnitDamageManager(const shared_ptr<const vector<shared_ptr<Component>>> components);
  void apply_damage(int damage);
private:
  void apply_damage_each(int damage);
  void damage_component(Component & component, int damage);
  shared_ptr<Component> healthiest_component() const;
  int alive_components_count() const;
  int applied_damage;
  int volatile_damage_triggered;
  const shared_ptr<const vector<shared_ptr<Component>>> components;
};
