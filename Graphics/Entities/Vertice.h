#ifndef VERTICE
#define VERTICE

namespace Entities {

class Vertice {
 public:
  double x;
  double y;
  double z;
  double w;
  Vertice() {}
  Vertice(double x, double y, double z, double w = 1): x(x), y(y), z(z), w(w) {}
};

} // Entities namespace

#endif  // !VERTICE
