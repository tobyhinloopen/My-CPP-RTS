#import "../weapon_template.h"
#import "../engine_template.h"
#import "../reactor_template.h"

class component_template_factory {
public:
  engine_template create_engine_template();
  weapon_template create_laser_weapon_template();
  weapon_template create_cannon_weapon_template();
  reactor_template create_reactor_template();
};
