#import "weapon_template.h"
#import "engine_template.h"
#import "reactor_template.h"
#import "component_template.h"
#import "component.h"
#import "component_set.h"

#import <vector>
#import <memory>

class UnitTemplate {
public:
  UnitTemplate();
  void add(const ComponentTemplate &);
  int mass() const;
  int health() const;
  int complexity() const;
  std::shared_ptr<ComponentSet> components() const;
private:
  std::vector<ComponentTemplate> _component_templates;
};
