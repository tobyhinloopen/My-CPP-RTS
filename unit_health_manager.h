#import "componentable.h"

class UnitHealthManager : private virtual Componentable {
public:
  UnitHealthManager(const shared_ptr<const vector<shared_ptr<Component>>> components);
  int initial_health() const;
  int health() const;
  bool dead() const;
  bool alive() const;
  static int health_for_components(const shared_ptr<const vector<shared_ptr<Component>>> components);
private:
  const int _initial_health;
};
