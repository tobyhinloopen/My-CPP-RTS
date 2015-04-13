#import "component.h"
#import "component_template.h"

class TemplateComponent : public Component {
public:
  TemplateComponent(ComponentTemplate component_template);
  virtual int mass() const;
  virtual int volatility() const;
private:
  const ComponentTemplate _component_template;
};
