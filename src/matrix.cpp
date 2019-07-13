//
// Created by Haoda Fu on 2019-06-27.
//
#include "matrix.h"
#include "utils.h"

aads::data::Matrix::Matrix(aads::data::Matrix &&rhs) noexcept {
  rowMajorData_ = std::move(rhs.rowMajorData_);
  // colMajorData_ = std::move(rhs.colMajorData_);
  nCol_ = rhs.nCol_;
  nRow_ = rhs.nRow_;
}

aads::data::Matrix &aads::data::Matrix::operator=(Matrix &&rhs) noexcept {
  rowMajorData_ = std::move(rhs.rowMajorData_);
  // colMajorData_ = std::move(rhs.colMajorData_);
  nCol_ = rhs.nCol_;
  nRow_ = rhs.nRow_;
  return *this;
}

aads::data::Matrix::Matrix(size_t nRow, size_t nCol) : nCol_{nCol}, nRow_{nRow} {
  rowMajorData_.resize(nRow * nCol);
  std::fill(rowMajorData_.begin(), rowMajorData_.end(), 0);
}

aads::data::IteratorFactory aads::data::Matrix::row(size_t rowID) {
  utils::assertTrue(rowID < nRow_, "Row index is out of bound!");
  return IteratorFactory(rowMajorData_.data() + rowID * nCol_, rowMajorData_.data() + (rowID + 1) * nCol_, 1);
}

aads::data::IteratorFactory aads::data::Matrix::row(size_t rowID) const {
  utils::assertTrue(rowID < nRow_, "Row index is out of bound!");
  return IteratorFactory(rowMajorData_.data() + rowID * nCol_, rowMajorData_.data() + (rowID + 1) * nCol_, 1);
}

aads::data::real &aads::data::Matrix::operator()(size_t row, size_t col) {
  utils::assertTrue(row < nRow_ && col < nCol_, "Row index or column index is out of bound!");
  return rowMajorData_[row * nCol_ + col];
}

aads::data::IteratorFactory aads::data::Matrix::col(size_t colID) {
  utils::assertTrue(colID < nCol_, "Column index is out of bound");
  return aads::data::IteratorFactory(rowMajorData_.data() + colID, rowMajorData_.data() + colID + nRow_ * nCol_, nCol_);
}

aads::data::IteratorFactory aads::data::Matrix::col(size_t colID) const {
  utils::assertTrue(colID < nCol_, "Column index is out of bound");
  return aads::data::IteratorFactory(rowMajorData_.data() + colID,
                                     rowMajorData_.data() + colID + nRow_ * nCol_,
                                     nCol_);
}
const aads::data::real &aads::data::Matrix::operator()(size_t row, size_t col) const {
  utils::assertTrue(row < nRow_ && col < nCol_, "Row index or column index is out of bound!");
  return rowMajorData_[row * nCol_ + col];
}

aads::data::Matrix &aads::data::Matrix::operator+=(const aads::data::Matrix &rhs) {
  utils::assertTrue(nRow_ == rhs.nRow_, "Number of rows does not match!");
  utils::assertTrue(nCol_ == rhs.nCol_, "Number of columns does not match!");
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 rhs.rowMajorData_.begin(),
                 rowMajorData_.begin(),
                 std::plus<>());
  return *this;
}

aads::data::Matrix &aads::data::Matrix::operator-=(const aads::data::Matrix &rhs) {
  utils::assertTrue(nRow_ == rhs.nRow_, "Number of rows does not match!");
  utils::assertTrue(nCol_ == rhs.nCol_, "Number of columns does not match!");
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 rhs.rowMajorData_.begin(),
                 rowMajorData_.begin(),
                 std::minus<>());
  return *this;
}

aads::data::Matrix aads::data::Matrix::operator+(const aads::data::Matrix &rhs) const {
  utils::assertTrue(nRow_ == rhs.nRow_, "Number of rows does not match!");
  utils::assertTrue(nCol_ == rhs.nCol_, "Number of columns does not match!");
  Matrix newMatrix(nRow_, nCol_);
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 rhs.rowMajorData_.begin(),
                 newMatrix.rowMajorData_.begin(),
                 std::plus<>());
  return newMatrix;
}

aads::data::Matrix aads::data::Matrix::operator-(const aads::data::Matrix &rhs) const {
  utils::assertTrue(nRow_ == rhs.nRow_, "Number of rows does not match!");
  utils::assertTrue(nCol_ == rhs.nCol_, "Number of columns does not match!");
  Matrix newMatrix(nRow_, nCol_);
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 rhs.rowMajorData_.begin(),
                 newMatrix.rowMajorData_.begin(),
                 std::minus<>());
  return newMatrix;
}

aads::data::Matrix &aads::data::Matrix::operator*=(aads::data::real a) {
  std::transform(rowMajorData_.begin(), rowMajorData_.end(), rowMajorData_.begin(), [a](auto &c) { return c * a; });
  return *this;
}

aads::data::Matrix &aads::data::Matrix::operator/=(aads::data::real a) {
  std::transform(rowMajorData_.begin(), rowMajorData_.end(), rowMajorData_.begin(), [a](auto &c) { return c / a; });
  return *this;
}

aads::data::Matrix aads::data::Matrix::operator*(aads::data::real a) const {
  Matrix newMatrix(nRow_, nCol_);
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 newMatrix.rowMajorData_.begin(),
                 [a](auto &c) { return c * a; });
  return newMatrix;
}

aads::data::Matrix aads::data::Matrix::operator/(aads::data::real a) const {
  Matrix newMatrix(nRow_, nCol_);
  std::transform(rowMajorData_.begin(),
                 rowMajorData_.end(),
                 newMatrix.rowMajorData_.begin(),
                 [a](auto &c) { return c / a; });
  return newMatrix;
}

// matrix C = A * B (A is in current class, and B is in rhs)
aads::data::Matrix aads::data::Matrix::operator*(const aads::data::Matrix & rhs) const{
  utils::assertTrue(nCol_==rhs.nRow_, "Matrix size does not match for conduct the product operation!");
  Matrix newMatrix(nRow_, rhs.nCol_);

  for(size_t colIter = 0 ; colIter < rhs.nCol_; ++colIter){
    const real * lhs = rowMajorData_.data();
    for(auto iter = newMatrix.col(colIter).begin(); iter != newMatrix.col(colIter).end(); ++iter){
      real temp =0;
      for(auto rhsColIter = rhs.col(colIter).cbegin(); rhsColIter != rhs.col(colIter).cend(); ++rhsColIter){
        temp += (*lhs) * (*rhsColIter);
        ++lhs;
      }
      *iter = temp;
    }
  }
  return newMatrix;
}

