#import "damage_report.h"
#import "componentable.h"

class unit_damage_manager : private virtual componentable {
public:
  unit_damage_manager(const std::shared_ptr<const component_set> components);
  damage_report apply_damage(const damage_t damage);
private:
  component & healthiest_component() const;
  short_size_t alive_components_count() const;
};
