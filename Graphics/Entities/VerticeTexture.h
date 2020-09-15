#ifndef VERTICETEXTURE
#define VERTICETEXTURE

namespace Entities {

class VerticeTexture {
 public:
  double u;
  double v;
  double w;
  VerticeTexture() {}
  VerticeTexture(double u, double v = 1, double w = 1): u(u), v(v), w(w) {}
};

} // Entities namespace

#endif  // !VERTICETEXTURE