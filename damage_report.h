#import "types.h"

class damage_report {
public:
  damage_report();
  damage_report & operator+=(const damage_report & other);
  damage_t damage_applied;
  damage_t volatility_triggered;
};
