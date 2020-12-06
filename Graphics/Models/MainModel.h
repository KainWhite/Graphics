#ifndef MAINMODEL
#define MAINMODEL

#include "windows.h"
#include "../DTOs/ParsedObjFile.h"

class MainModel {
 public:
  std::vector<Entities::Vertice> vertices;
  std::vector<Entities::VerticeTexture> verticeTextures;
  std::vector<Entities::VerticeNorm> verticeNorms;
  std::vector<Entities::Polygon> polygons;

  MainModel() {}

  void LoadState(ParsedObjFile const &state);

  void Translate(int x, int y, int z);

  void Rotate(int x, int y, int z);

  void Scale(int x, int y, int z);
};

#endif // !MAINMODEL

