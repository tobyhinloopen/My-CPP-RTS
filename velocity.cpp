#import "velocity.h"

Velocity::Velocity(short x, short y): x(x), y(y) {}

Velocity::Velocity(): x(0), y(0) {}

bool Velocity::none() const {
  return x == 0 && y == 0;
}

bool Velocity::any() const {
  return !none();
}

Velocity & Velocity::operator+=(const Velocity & other) {
  x += other.x;
  y += other.y;
  return *this;
}
