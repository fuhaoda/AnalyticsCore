//
// Created by Haoda Fu on 2019-06-26.
//

#ifndef ANALYTICSCORE_INCLUDE_MATRIX_H_
#define ANALYTICSCORE_INCLUDE_MATRIX_H_

#include <vector>
#include "base.h"
#include "iterator.h"

namespace aads::data {

class Matrix {
 public:
  // constructor for an empty matrix with 0 entries
  Matrix(size_t r, size_t c);
  Matrix() = delete;

  // move constructor
  Matrix(Matrix &&) noexcept;
  // move assignment constructor
  Matrix &operator=(Matrix &&) noexcept;

  ~Matrix() = default;

  // copy constructor
  Matrix(const Matrix &) = default;

  // copy assignment constructor
  Matrix &operator=(const Matrix &) = default;

  // return a column iterator
  aads::data::IteratorFactory  col(size_t colID);
  aads::data::IteratorFactory const  col(size_t colID) const;

  // return a row iterator
  aads::data::IteratorFactory row(size_t rowID);
  aads::data::IteratorFactory const row(size_t rowID) const;
  // return an item in a matrix
  real &operator()(size_t row, size_t col);
  const real &operator()(size_t row, size_t col) const;

  // matrix element by element operations
  Matrix &operator+=(const Matrix &);
  Matrix &operator-=(const Matrix &);
  Matrix operator+(const Matrix &) const;
  Matrix operator-(const Matrix &) const;

  // scalar operations
  Matrix &operator*=(real);
  Matrix &operator/=(real);
  Matrix operator *(real) const;
  Matrix operator /(real) const;

  Matrix operator*(const Matrix &) const;

  // matrix functions
  static Matrix inv(const Matrix &);
  static Matrix solve(const Matrix &, const Matrix &);
  static void Cholesky();
  static void LU();
  static void QR();
  static void SVD();

  static void eigen(const Matrix &, std::vector<real> &eigenValues, Matrix &eigenVectors);

 private:
  std::vector<real> rowMajorData_;
//  std::vector<real> colMajorData_;
  size_t nRow_;
  size_t nCol_;

};

}
// namespace aads::data
#endif //ANALYTICSCORE_INCLUDE_MATRIX_H_
