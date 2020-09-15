#include "MainModel.h"

void MainModel::LoadState(ParsedObjFile const &state) {
  vertices = state.vertices;
  verticeTextures = state.verticeTextures;
  verticeNorms = state.verticeNorms;
  polygons = state.polygons;
  InvalidateRect(hwnd, nullptr, false);
}