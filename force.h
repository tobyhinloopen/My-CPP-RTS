#import "types.h"

class force_t {
public:
  force_t();
  force_t(const force_magnitude_t x, const force_magnitude_t y);
  force_t & operator+=(const force_t & other);
  bool any() const;
  bool none() const;
  force_magnitude_t x;
  force_magnitude_t y;
};
