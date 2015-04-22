#import "component.h"
#import "component_set.h"
#import "damage_report.h"
#import "componentable.h"
#import <vector>
#import <memory>

class UnitDamageManager : private virtual Componentable {
public:
  UnitDamageManager(const std::shared_ptr<const ComponentSet> components);
  DamageReport apply_damage(const int damage);
private:
  Component & healthiest_component() const;
  int alive_components_count() const;
};
