class force_t {
public:
  force_t();
  force_t(const double x, const double y);
  force_t & operator+=(const force_t & other);
  bool any() const;
  bool none() const;
  double x;
  double y;
};
