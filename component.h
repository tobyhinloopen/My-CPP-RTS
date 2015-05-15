#import "damage_report.h"
#import "force.h"
#import "types.h"

class component {
public:
  component(const health_t health);
  virtual ~component();
  virtual damage_report apply_damage(const damage_t damage);
  virtual mass_t mass() const;
  virtual volatility_t volatility() const;
  virtual force_t force() const;
  health_t health() const;
  bool alive() const;
  bool dead() const;
private:
  health_t _health;
};
