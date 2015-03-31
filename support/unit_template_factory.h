#import "../unit_template.h"
#import "component_template_factory.h"

class UnitTemplateFactory {
  ComponentTemplateFactory component_template_factory;
public:
  UnitTemplate create_unit_template();
};
