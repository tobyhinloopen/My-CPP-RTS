#import "componentable.h"

class unit_health_manager : private virtual componentable {
public:
  unit_health_manager(const std::shared_ptr<const component_set> components);
  double initial_health() const;
  double health() const;
  bool dead() const;
  bool alive() const;
  static double health_for_components(const std::shared_ptr<const component_set> components);
private:
  const double _initial_health;
};
