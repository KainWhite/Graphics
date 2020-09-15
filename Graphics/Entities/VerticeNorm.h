#ifndef VERTICENORM
#define VERTICENORM

namespace Entities {

class VerticeNorm {
 public:
  double i;
  double j;
  double k;
  VerticeNorm() {}
  VerticeNorm(double i, double j, double k): i(i), j(j), k(k) {}
};

} // Entities namespace

#endif // !VERTICENORM