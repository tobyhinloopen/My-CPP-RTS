#import "template_component.h"

TemplateComponent::TemplateComponent(ComponentTemplate component_template):
Component(component_template.health),
component_template(component_template) {
}

int TemplateComponent::mass() const {
  return component_template.mass;
}

int TemplateComponent::volatility() const {
  return component_template.volatility;
}