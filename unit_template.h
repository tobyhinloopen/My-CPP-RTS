#import "component_set.h"
#import "component_template.h"

class UnitTemplate {
public:
  UnitTemplate();
  void add(const ComponentTemplate &);
  int mass() const;
  int health() const;
  int complexity() const;
  std::unique_ptr<ComponentSet> create_components() const;
private:
  std::vector<ComponentTemplate> _component_templates;
};
