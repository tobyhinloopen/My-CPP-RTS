class velocity_t {
public:
  velocity_t();
  velocity_t(short x, short y);
  velocity_t & operator+=(const velocity_t & other);
  bool any() const;
  bool none() const;
  short x;
  short y;
};
