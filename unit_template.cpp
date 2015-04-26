#import "unit_template.h"
#import "template_component.h"

UnitTemplate::UnitTemplate() {}

void UnitTemplate::add(const ComponentTemplate & component_template) {
  _component_templates.push_back(component_template);
}

std::unique_ptr<ComponentSet> UnitTemplate::create_components() const {
  auto components = std::unique_ptr<ComponentSet>(new ComponentSet());
  for(const auto component_template : _component_templates)
    components->push_back(std::make_shared<TemplateComponent>(component_template));
  return components;
}

int UnitTemplate::mass() const {
  int mass = 0;
  for(const auto component_template : _component_templates)
    mass += component_template.mass;
  return mass;
}

int UnitTemplate::complexity() const {
  int complexity = 0;
  for(const auto component_template : _component_templates)
    complexity += component_template.complexity;
  return complexity;
}

int UnitTemplate::health() const {
  int health = 0;
  for(const auto component_template : _component_templates)
    health += component_template.health;
  return health;
}
