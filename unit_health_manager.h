#import "componentable.h"

class unit_health_manager : private virtual componentable {
public:
  unit_health_manager(const std::shared_ptr<const component_set> components);
  health_t initial_health() const;
  health_t health() const;
  bool dead() const;
  bool alive() const;
private:
  const health_t _initial_health;
};
