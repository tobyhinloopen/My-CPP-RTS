#import "damage_report.h"
#import "componentable.h"

class unit_damage_manager : private virtual componentable {
public:
  unit_damage_manager(const std::shared_ptr<const component_set> components);
  damage_report apply_damage(const double damage);
private:
  component & healthiest_component() const;
  int alive_components_count() const;
};
