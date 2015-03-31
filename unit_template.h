#import "weapon_template.h"
#import "engine_template.h"
#import "reactor_template.h"
#import "component_template.h"
#import "component.h"

#include <vector>

class UnitTemplate {
public:
  UnitTemplate();
  void add(const ComponentTemplate &);
  int mass() const;
  int health() const;
  int complexity() const;
  std::vector<Component> components() const;
private:
  std::vector<ComponentTemplate> component_templates;
};
