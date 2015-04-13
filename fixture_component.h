#import "component.h"

class FixtureComponent : public Component {
public:
  FixtureComponent(int health);
  virtual int mass() const;
  void mass(int mass);
  virtual int volatility() const;
  void volatility(int volatility);
  virtual Force force() const;
  void force(Force force);
private:
  int _mass;
  int _volatility;
  Force _force;
};
