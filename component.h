#import "component_template.h"
#import "damage_report.h"

class Component {
public:
  Component(ComponentTemplate component_template);
  DamageReport apply_damage(int damage);
  int mass() const;
  int health() const;
  int volatility() const;
  bool alive() const;
  bool dead() const;
private:
  const ComponentTemplate component_template;
  int current_health;
};
