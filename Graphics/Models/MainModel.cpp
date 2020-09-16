#include "MainModel.h"

void MainModel::LoadState(ParsedObjFile const &state) {
  vertices = state.vertices;
  verticeTextures = state.verticeTextures;
  verticeNorms = state.verticeNorms;
  polygons = state.polygons;
  for (auto vertice : vertices) {

  }
  InvalidateRect(hwnd, nullptr, false);
}

void MainModel::Translate(int x, int y, int z) {

}