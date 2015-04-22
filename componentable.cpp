#import "componentable.h"

Componentable::Componentable(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components):
components(components) {
}
