#ifndef MAINMODEL
#define MAINMODEL

#include "windows.h"
#include "../DTOs/ParsedObjFile.h"

class MainModel {
 public:
  HWND hwnd;

  std::vector<Entities::Vertice> vertices;
  std::vector<Entities::VerticeTexture> verticeTextures;
  std::vector<Entities::VerticeNorm> verticeNorms;
  std::vector<Entities::Polygon> polygons;

  MainModel(HWND hwnd) : hwnd(hwnd) {}

  void LoadState(ParsedObjFile const &state);
};

#endif // !MAINMODEL

