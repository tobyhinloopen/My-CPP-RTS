#import "component.h"
#import "component_set.h"
#import <memory>

class componentable {
protected:
  componentable(const std::shared_ptr<const component_set> components);
  const std::shared_ptr<const component_set> components;
};
