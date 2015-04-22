#import "componentable.h"

class UnitHealthManager : private virtual Componentable {
public:
  UnitHealthManager(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components);
  int initial_health() const;
  int health() const;
  bool dead() const;
  bool alive() const;
  static int health_for_components(const std::shared_ptr<const std::vector<std::shared_ptr<Component>>> components);
private:
  const int _initial_health;
};
