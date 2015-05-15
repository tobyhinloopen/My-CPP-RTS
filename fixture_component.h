#import "component.h"

class fixture_component : public component {
public:
  fixture_component(health_t health);
  virtual mass_t mass() const;
  void mass(mass_t mass);
  virtual volatility_t volatility() const;
  void volatility(volatility_t volatility);
  virtual force_t force() const;
  void force(force_t force);
private:
  mass_t _mass;
  volatility_t _volatility;
  force_t _force;
};
