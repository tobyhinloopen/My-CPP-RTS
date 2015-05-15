#import "component_set.h"
#import "component_template.h"

class unit_template {
public:
  unit_template();
  void add(const component_template &);
  double mass() const;
  double health() const;
  double complexity() const;
  std::unique_ptr<component_set> create_components() const;
private:
  std::vector<component_template> _component_templates;
};
