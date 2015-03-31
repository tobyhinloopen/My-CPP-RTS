#import "unit_template_factory.h"

UnitTemplate UnitTemplateFactory::create_unit_template() {
  UnitTemplate unit_template;
  unit_template.add(component_template_factory.create_cannon_weapon_template());
  unit_template.add(component_template_factory.create_laser_weapon_template());
  unit_template.add(component_template_factory.create_engine_template());
  unit_template.add(component_template_factory.create_reactor_template());
  return unit_template;
}
