#import "force.h"

force_t::force_t(const double x, const double y): x(x), y(y) {}

force_t::force_t(): x(0.0), y(0.0) {}

bool force_t::none() const {
  return x == 0.0 && y == 0.0;
}

bool force_t::any() const {
  return !none();
}

force_t & force_t::operator+=(const force_t & other) {
  x += other.x;
  y += other.y;
  return *this;
}
