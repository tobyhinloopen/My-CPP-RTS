#import "component.h"
#import "damage_report.h"
#import <vector>
#import <memory>

using namespace std;

class UnitDamageManager {
public:
  UnitDamageManager(const shared_ptr<const vector<shared_ptr<Component>>> components);
  DamageReport apply_damage(const int damage);
private:
  shared_ptr<Component> healthiest_component() const;
  int alive_components_count() const;
  const shared_ptr<const vector<shared_ptr<Component>>> components;
};
