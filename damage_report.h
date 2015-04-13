#import "damage.h"

class DamageReport {
public:
  DamageReport();
  DamageReport & operator+=(const DamageReport & other);
  Damage damage_applied;
  Damage volatility_triggered;
};
