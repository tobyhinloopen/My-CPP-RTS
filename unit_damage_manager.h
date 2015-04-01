#import "component.h"
#import "damage_report.h"
#import "componentable.h"
#import <vector>
#import <memory>

using namespace std;

class UnitDamageManager : private virtual Componentable {
public:
  UnitDamageManager(const shared_ptr<const vector<shared_ptr<Component>>> components);
  DamageReport apply_damage(const int damage);
private:
  Component & healthiest_component() const;
  int alive_components_count() const;
};
