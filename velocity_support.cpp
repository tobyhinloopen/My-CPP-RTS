#import "velocity_support.h"

std::ostream & operator<<(std::ostream & out, velocity_t const & velocity) { 
  return out << "velocity_t(" << velocity.x << ", " << velocity.y << ")";
}
