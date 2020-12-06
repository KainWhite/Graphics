#include "Matrix.h"
#include <Windows.h>
#include <stdexcept>
#include <sstream>
#include <iomanip>

Matrix::Matrix(int height, int width) : height(height), width(width) {
  for (int i = 0; i < height; i++) {
    std::vector<double> row(width, 0);
    values.push_back(row);
  }
}

Matrix::Matrix(Matrix const& other) {
  *this = other;
}

Matrix::Matrix(std::vector<std::vector<double>> const &values) : values(values) {
  height = values.size();
  width = values.begin()->size();
}

void Matrix::Display() const {
  std::stringstream result;
  result << std::fixed << std::setprecision(3);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      result << values[i][j] << "\t";
    }
    result << std::endl;
  }
  OutputDebugStringA(result.str().c_str());
}

void Matrix::DisplayTranspose() const {
  std::stringstream result;
  result << std::fixed << std::setprecision(3);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      result << values[j][i] << "\t";
    }
    result << std::endl;
  }
  OutputDebugStringA(result.str().c_str());
}

Matrix Matrix::operator*(Matrix const &other) const {
  if (width != other.height) {
    throw std::runtime_error("Can't multiply matrix with a.width != b.height");
  }
  Matrix result(height, other.width);
  for (int i = 0; i < result.height; i++) {
    for (int j = 0; j < result.width; j++) {
      for (int k = 0; k < width; k++) {
        result[i][j] += values[i][k] * other[k][j];
      }
    }
  }
  return result;
}

Matrix Matrix::operator*=(Matrix const &other) {
  auto result = *this * other;
  this->values = result.values;
  return result;
}

Matrix Matrix::operator/(double x) const {
  Matrix result(height, width);
  for (int i = 0; i < result.height; i++) {
    for (int j = 0; j < result.width; j++) {
      result[i][j] = values[i][j] / x;
    }
  }
  return result;
}

Matrix Matrix::operator/=(double x) {
  auto result = *this / x;
  this->values = result.values;
  return result;
}

std::vector<double> &Matrix::operator[](int const i) {
  return values[i];
}

std::vector<double> Matrix::operator[](int const i) const {
  return values[i];
}