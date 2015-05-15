#import "damage_report.h"

damage_report::damage_report():
damage_applied(0),
volatility_triggered(0) {
}

damage_report & damage_report::operator+=(const damage_report & other) {
  damage_applied += other.damage_applied;
  volatility_triggered += other.volatility_triggered;
  return *this;
}
