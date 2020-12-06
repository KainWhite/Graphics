#include "MainModel.h"

void MainModel::LoadState(ParsedObjFile const &state) {
  vertices = state.vertices;
  verticeTextures = state.verticeTextures;
  verticeNorms = state.verticeNorms;
  polygons = state.polygons;
}

void MainModel::Translate(int x, int y, int z) {
  Matrix translationMatrix(std::vector<std::vector<double>>{
    {1, 0, 0, (double)x},
    {0, 1, 0, (double)y},
    {0, 0, 1, (double)z},
    {0, 0, 0, 1}
  });
  for (auto &vertice : vertices) {
    vertice.position = translationMatrix * vertice.position;
  }
}

void MainModel::Rotate(int x, int y, int z) {
  Matrix rotationXMatrix(std::vector<std::vector<double>>{
    {1, 0, 0, 0},
    {0, cos(x), -sin(x), 0},
    {0, sin(x), cos(x), 0},
    {0, 0, 0, 1}
  });
  Matrix rotationYMatrix(std::vector<std::vector<double>>{
    {1, 0, 0, 0},
    {0, cos(y), -sin(y), 0},
    {0, sin(y), cos(y), 0},
    {0, 0, 0, 1}
  });
  Matrix rotationZMatrix(std::vector<std::vector<double>>{
    {cos(z), -sin(z), 0, 0},
    {-sin(z), cos(z), 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
  });
  Matrix rotationMatrix(rotationXMatrix * rotationYMatrix * rotationZMatrix);
  for (auto &vertice : vertices) {
    vertice.position = rotationMatrix * vertice.position;
  }
}

void MainModel::Scale(int x, int y, int z) {
  Matrix scaleMatrix(std::vector<std::vector<double>>{
    {(double)x, 0, 0, 0},
    {0, (double)y, 0, 0},
    {0, 0, (double)z, 0},
    {0, 0, 0, 1}
  });
  for (auto &vertice : vertices) {
    vertice.position = scaleMatrix * vertice.position;
  }
}

