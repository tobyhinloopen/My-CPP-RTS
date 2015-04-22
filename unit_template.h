#import "component_set.h"
#import "component_template.h"

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
