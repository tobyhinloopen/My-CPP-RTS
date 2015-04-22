#import <memory>
#import <vector>
#import "component.h"

class Componentable {
protected:
  Componentable(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components);
  const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components;
};
