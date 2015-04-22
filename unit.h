#import "unit_damage_manager.h"
#import "unit_health_manager.h"

class Unit : private virtual Componentable, public UnitHealthManager, public UnitDamageManager {
public:
  Unit(const std::shared_ptr<const ComponentSet> components);
  int mass() const;
};
