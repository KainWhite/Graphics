#ifndef VERTICE
#define VERTICE

#include "../Core/Matrix.h"

namespace Entities {

class Vertice {
 public:
  Matrix position;

  Vertice(): position(Matrix(3, 1)) {}
  Vertice(Matrix position): position(position) {}
};

} // Entities namespace

#endif  // !VERTICE
