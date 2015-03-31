#import "unit_damage_manager.h"
#import "component.h"
#import <vector>
#import <memory>

using namespace std;

class Unit {
public:
  Unit(shared_ptr<vector<shared_ptr<Component>>> components);
  int health() const;
  int mass() const;
  void apply_damage(int damage);
private:
  UnitDamageManager unit_damage_manager;
  shared_ptr<vector<shared_ptr<Component>>> components;
};
