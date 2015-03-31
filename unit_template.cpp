#import "unit_template.h"

using namespace std;

UnitTemplate::UnitTemplate() {
}

void UnitTemplate::add(const ComponentTemplate & component_template) {
  component_templates.push_back(component_template);
}

shared_ptr<vector<shared_ptr<Component>>> UnitTemplate::components() const {
  auto components = make_shared<vector<shared_ptr<Component>>>();
  for(auto component_template = component_templates.begin();
      component_template != component_templates.end();
      ++component_template)
    components->push_back(make_shared<Component>(*component_template));
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
