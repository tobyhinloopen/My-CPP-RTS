#import <memory>
#import <vector>
#import "component.h"

using namespace std;

class Componentable {
protected:
  Componentable(const shared_ptr<const vector<shared_ptr<Component>>> components);
  const shared_ptr<const vector<shared_ptr<Component>>> components;
};
