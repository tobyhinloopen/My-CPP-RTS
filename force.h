class Force {
public:
  Force();
  Force(short x, short y);
  Force & operator+=(const Force & other);
  bool any() const;
  bool none() const;
  short x;
  short y;
};
