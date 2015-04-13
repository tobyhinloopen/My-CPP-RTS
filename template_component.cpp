#import "template_component.h"

TemplateComponent::TemplateComponent(ComponentTemplate component_template):
Component(component_template.health),
_component_template(component_template) {
}

int TemplateComponent::mass() const {
  return _component_template.mass;
}

int TemplateComponent::volatility() const {
  return _component_template.volatility;
}
