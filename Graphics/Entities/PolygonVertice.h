#ifndef POLYGONVERTICE
#define POLYGONVERTICE

#include <optional>

namespace Entities {

class PolygonVertice {
 public:
  int verticeNumber;
  std::optional<int> verticeTextureNumber;
  std::optional<int> verticeNormNumber;
  PolygonVertice() {}
  PolygonVertice(int verticeNumber,
                 std::optional<int> verticeTextureNumber = std::nullopt,
                 std::optional<int> verticeNormNumber = std::nullopt)
      : verticeNumber(verticeNumber),
        verticeTextureNumber(verticeTextureNumber),
        verticeNormNumber(verticeNormNumber) {}
};

} // Entities namespace

#endif  // !POLYGONVERTICE
