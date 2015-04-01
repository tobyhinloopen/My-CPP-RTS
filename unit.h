#import "unit_damage_manager.h"
#import "component.h"
#import "damage_report.h"
#import "componentable.h"
#import <vector>
#import <memory>

using namespace std;

class Unit : private virtual Componentable, public UnitDamageManager {
public:
  Unit(const shared_ptr<const vector<shared_ptr<Component>>> components);
  int initial_health() const;
  int health() const;
  int mass() const;
  bool alive() const;
  bool dead() const;
private:
  const int _initial_health;
};
