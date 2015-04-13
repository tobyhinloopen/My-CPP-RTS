#import "force.h"

Force::Force(short x, short y): x(x), y(y) {}

Force::Force(): x(0), y(0) {}

bool Force::none() const {
  return x == 0 && y == 0;
}

bool Force::any() const {
  return !none();
}

Force & Force::operator+=(const Force & other) {
  x += other.x;
  y += other.y;
  return *this;
}
