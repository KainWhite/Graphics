#include "Matrix.h"

Matrix::Matrix(int height, int width) : height(height), width(width) {
  for (int i = 0; i < height; i++) {
    std::vector<double> row(width, 0);
    values.push_back(row);
  }
}

Matrix::Matrix(Matrix const& other) {
  *this = other;
}

Matrix::Matrix(std::vector<std::vector<double>> values) : values(values) {
  height = values.size();
  width = values[0].size();
}

Matrix Matrix::operator*(Matrix const &other) const {
  if (width != other.height) {
    throw;
  }
  Matrix result(height, other.width);
  for (int i = 0; i < result.height; i++) {
    for (int j = 0; j < result.width; j++) {
      for (int k = 0; k < width; k++) {
        result[i][j] += values[i][k] * other[k][j];
      }
    }
  }
}

std::vector<double> &Matrix::operator[](int const i) {
  return values[i];
}

std::vector<double> Matrix::operator[](int const i) const {
  return values[i];
}