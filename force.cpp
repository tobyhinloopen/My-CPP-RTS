#import "force.h"

force_t::force_t(): x(0), y(0) {
}

force_t::force_t(const force_magnitude_t x, const force_magnitude_t y): x(x), y(y) {
}

bool force_t::none() const {
  return x == 0 && y == 0;
}

bool force_t::any() const {
  return !none();
}

force_t & force_t::operator+=(const force_t & other) {
  x += other.x;
  y += other.y;
  return *this;
}
