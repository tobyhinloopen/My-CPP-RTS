class Force {
public:
  Force();
  Force & operator+=(const Force & other);
  bool any() const;
  bool none() const;
  short x;
  short y;
};
