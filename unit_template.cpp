#import "unit_template.h"
#import "template_component.h"

using namespace std;

UnitTemplate::UnitTemplate()
{}

void UnitTemplate::add(const ComponentTemplate & component_template) {
  component_templates.push_back(component_template);
}

shared_ptr<vector<shared_ptr<Component>>> UnitTemplate::components() const {
  auto components = make_shared<vector<shared_ptr<Component>>>();
  for(const auto component_template : component_templates)
    components->push_back(make_shared<TemplateComponent>(component_template));
  return components;
}

int UnitTemplate::mass() const {
  int mass = 0;
  for(const auto component_template : component_templates)
    mass += component_template.mass;
  return mass;
}

int UnitTemplate::complexity() const {
  int complexity = 0;
  for(const auto component_template : component_templates)
    complexity += component_template.complexity;
  return complexity;
}

int UnitTemplate::health() const {
  int health = 0;
  for(const auto component_template : component_templates)
    health += component_template.health;
  return health;
}
