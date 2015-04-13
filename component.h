#import "damage_report.h"
#import "force.h"

class Component {
public:
  Component(int health);
  virtual ~Component();
  virtual DamageReport apply_damage(int damage);
  virtual int mass() const;
  virtual int volatility() const;
  virtual Force force() const;
  int health() const;
  bool alive() const;
  bool dead() const;
private:
  int _health;
};
