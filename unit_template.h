#import "weapon_template.h"
#import "engine_template.h"
#import "reactor_template.h"
#import "component_template.h"
#import "component.h"

#import <vector>
#import <memory>

using namespace std;

class UnitTemplate {
public:
  UnitTemplate();
  void add(const ComponentTemplate &);
  int mass() const;
  int health() const;
  int complexity() const;
  shared_ptr<vector<shared_ptr<Component>>> components() const;
private:
  vector<ComponentTemplate> component_templates;
};
