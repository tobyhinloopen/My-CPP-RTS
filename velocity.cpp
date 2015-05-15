#import "velocity.h"

velocity_t::velocity_t(short x, short y): x(x), y(y) {}

velocity_t::velocity_t(): x(0), y(0) {}

bool velocity_t::none() const {
  return x == 0 && y == 0;
}

bool velocity_t::any() const {
  return !none();
}

velocity_t & velocity_t::operator+=(const velocity_t & other) {
  x += other.x;
  y += other.y;
  return *this;
}
