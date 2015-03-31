#import "unit_template.h"

UnitTemplate::UnitTemplate() {
}

void UnitTemplate::add(const ComponentTemplate & component_template) {
  component_templates.push_back(component_template);
}

std::vector<Component> UnitTemplate::components() const {
  std::vector<Component> components;
  for(auto it = component_templates.begin(); it != component_templates.end(); ++it) {
    Component component(*it);
    components.push_back(component);
  }
  return components;
}

int UnitTemplate::mass() const {
  int mass = 0;
  for(auto it = component_templates.begin(); it != component_templates.end(); ++it)
    mass += it->mass;
  return mass;
}

int UnitTemplate::complexity() const {
  int complexity = 0;
  for(auto it = component_templates.begin(); it != component_templates.end(); ++it)
    complexity += it->complexity;
  return complexity;
}

int UnitTemplate::health() const {
  int health = 0;
  for(auto it = component_templates.begin(); it != component_templates.end(); ++it)
    health += it->health;
  return health;
}
