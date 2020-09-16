#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix {
 public:
  std::vector<std::vector<double>> values;
  int height;
  int width;

  Matrix(int height, int width);
  Matrix(Matrix const &other);
  Matrix(std::vector<std::vector<double>> values);

  Matrix operator*(Matrix const &other) const;

  std::vector<double> &operator[](int const i);

  std::vector<double> operator[](int const i) const;
};

#endif  // !MATRIX
