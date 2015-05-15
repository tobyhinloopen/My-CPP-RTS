#import "component_set.h"
#import "component_template.h"

class unit_template {
public:
  unit_template();
  void add(const component_template &);
  mass_t mass() const;
  health_t health() const;
  complexity_t complexity() const;
  std::unique_ptr<component_set> create_components() const;
private:
  std::vector<component_template> _component_templates;
};
