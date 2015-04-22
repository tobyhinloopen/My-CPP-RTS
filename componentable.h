#import <memory>
#import <vector>
#import "component.h"
#import "component_set.h"

class Componentable {
protected:
  Componentable(const std::shared_ptr<const ComponentSet> components);
  const std::shared_ptr<const ComponentSet> components;
};
