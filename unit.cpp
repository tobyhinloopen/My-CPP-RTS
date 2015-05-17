#import "unit.h"

unit::unit(const std::shared_ptr<const component_set> components):
componentable(components),
unit_health_manager(components),
unit_damage_manager(components) {
}
