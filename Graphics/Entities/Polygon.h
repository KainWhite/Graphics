#ifndef POLYGON
#define POLYGON

#include <vector>
#include "PolygonVertice.h"

namespace Entities {

class Polygon {
 public:
  std::vector<PolygonVertice> vertices;
};

} // Entities namespace

#endif  // !POLYGON
