#import "unit_damage_manager.h"
#import "unit_health_manager.h"
#import "component.h"
#import "damage_report.h"
#import <vector>
#import <memory>

class Unit : private virtual Componentable, public UnitHealthManager, public UnitDamageManager {
public:
  Unit(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components);
  int mass() const;
};
