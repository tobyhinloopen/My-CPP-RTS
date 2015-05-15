#import "component.h"
#import "component_template.h"

class template_component : public component {
public:
  template_component(component_template component_template);
  virtual double mass() const;
  virtual double volatility() const;
private:
  const component_template _component_template;
};
