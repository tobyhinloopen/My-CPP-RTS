class DamageReport {
public:
  DamageReport();
  DamageReport & operator+=(const DamageReport & other);
  int damage_applied;
  int volatility_triggered;
};
