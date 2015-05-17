#import "types.h"

class velocity_t {
public:
  velocity_t();
  velocity_t(const velocity_magnitude_t x, const velocity_magnitude_t y);
  bool any() const;
  bool none() const;
  velocity_t & operator+=(const velocity_t & other);
  bool operator==(const velocity_t & other);
  bool operator!=(const velocity_t & other);
  velocity_magnitude_t x;
  velocity_magnitude_t y;
};
