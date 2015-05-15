#import "template_component.h"

template_component::template_component(const component_template component_template):
component(component_template.health),
_component_template(component_template) {
}

mass_t template_component::mass() const {
  return _component_template.mass;
}

volatility_t template_component::volatility() const {
  return _component_template.volatility;
}
