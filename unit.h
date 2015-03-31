#import "unit_damage_manager.h"
#import "component.h"
#import <vector>
#import <memory>

using namespace std;

class Unit {
public:
  Unit(const shared_ptr<const vector<shared_ptr<Component>>> components);
  void apply_damage(const int damage);
  int initial_health() const;
  int health() const;
  int mass() const;
  bool alive() const;
  bool dead() const;
private:
  const int _initial_health;
  UnitDamageManager unit_damage_manager;
  const shared_ptr<const vector<shared_ptr<Component>>> components;
};
