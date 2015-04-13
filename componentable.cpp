#import "componentable.h"

Componentable::Componentable(const shared_ptr<const vector<shared_ptr<Component>>> components):
components(components) {
}
