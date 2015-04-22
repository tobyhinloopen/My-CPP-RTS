#import "unit_damage_manager.h"
#import "unit_health_manager.h"
#import "component.h"
#import "component_set.h"
#import "damage_report.h"
#import <vector>
#import <memory>

class Unit : private virtual Componentable, public UnitHealthManager, public UnitDamageManager {
public:
  Unit(const std::shared_ptr<const ComponentSet> components);
  int mass() const;
};
