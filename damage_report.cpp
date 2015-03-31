#import "damage_report.h"

DamageReport::DamageReport()
  : damage_applied(0)
  , volatility_triggered(0)
{}

DamageReport & DamageReport::operator+=(const DamageReport & other) {
  damage_applied += other.damage_applied;
  volatility_triggered += other.volatility_triggered;
  return *this;
}
