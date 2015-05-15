#import "component.h"
#import "component_template.h"

class template_component : public component {
public:
  template_component(const component_template component_template);
  virtual mass_t mass() const;
  virtual volatility_t volatility() const;
private:
  const component_template _component_template;
};
