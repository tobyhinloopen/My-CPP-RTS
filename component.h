#import "component_template.h"

class Component {
public:
  Component(ComponentTemplate component_template);
  int mass() const;
  int health() const;
  int volatility() const;

  void apply_damage(int damage);
  int damage_applied() const;
  bool alive() const;
  bool dead() const;
private:
  const ComponentTemplate component_template;
  int current_health;
  int current_damage_applied;
};
