#ifndef PARSEDOBJFILEMODEL
#define PARSEDOBJFILEMODEL

#include <vector>
#include "../Entities/Vertice.h"
#include "../Entities/VerticeNorm.h"
#include "../Entities/VerticeTexture.h"
#include "../Entities/Polygon.h"

class ParsedObjFile {
 public:
  std::vector<Entities::Vertice> vertices;
  std::vector<Entities::VerticeTexture> verticeTextures;
  std::vector<Entities::VerticeNorm> verticeNorms;
  std::vector<Entities::Polygon> polygons;
};

#endif // PARSEDOBJFILEMODEL