#ifndef MATRIX
#define MATRIX

#include <vector>
#include <initializer_list>

class Matrix {
 public:
  std::vector<std::vector<double>> values;
  int height;
  int width;

  Matrix(int height, int width);
  Matrix(Matrix const &other);
  Matrix(std::vector<std::vector<double>> const &values);

  void Display() const;
  void DisplayTranspose() const;

  Matrix operator*(Matrix const &other) const;

  Matrix operator*=(Matrix const &other);

  Matrix operator/(double x) const;

  Matrix operator/=(double x);

  std::vector<double> &operator[](int const i);

  std::vector<double> operator[](int const i) const;
};

#endif  // !MATRIX
