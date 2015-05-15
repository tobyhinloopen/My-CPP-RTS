#import "template_component.h"

template_component::template_component(component_template component_template):
component(component_template.health),
_component_template(component_template) {
}

double template_component::mass() const {
  return _component_template.mass;
}

double template_component::volatility() const {
  return _component_template.volatility;
}
