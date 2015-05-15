#import "unit_damage_manager.h"
#import "unit_health_manager.h"

class unit : private virtual componentable, public unit_health_manager, public unit_damage_manager {
public:
  unit(const std::shared_ptr<const component_set> components);
  mass_t mass() const;
};
