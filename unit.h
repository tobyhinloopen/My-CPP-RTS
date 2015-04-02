#import "unit_damage_manager.h"
#import "unit_health_manager.h"
#import "component.h"
#import "damage_report.h"
#import <vector>
#import <memory>

using namespace std;

class Unit : private virtual Componentable, public UnitHealthManager, public UnitDamageManager {
public:
  Unit(const shared_ptr<const vector<shared_ptr<Component>>> components);
  int mass() const;
};
