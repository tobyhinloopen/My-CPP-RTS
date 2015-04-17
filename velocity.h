class Velocity {
public:
  Velocity();
  Velocity(short x, short y);
  Velocity & operator+=(const Velocity & other);
  bool any() const;
  bool none() const;
  short x;
  short y;
};
