#import "../weapon_template.h"
#import "../engine_template.h"
#import "../reactor_template.h"

class ComponentTemplateFactory {
public:
  EngineTemplate create_engine_template();
  WeaponTemplate create_laser_weapon_template();
  WeaponTemplate create_cannon_weapon_template();
  ReactorTemplate create_reactor_template();
};
