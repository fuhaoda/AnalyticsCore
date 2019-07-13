//
// Created by Haoda Fu on 2019-07-03.
//

#ifndef ANALYTICSCORE_TEST_TEST_MATRIX_COL_ITER_H_
#define ANALYTICSCORE_TEST_TEST_MATRIX_COL_ITER_H_

#include "base.h"
namespace aads::test {
class TestMatrixColIter : public aads::utils::Test {
 public:
  TestMatrixColIter(const std::string &string) : Test(string) {};
  void doTest() override {
    size_t nRow = 6;
    size_t nCol = 5;
    data::Matrix myMatrix(nRow, nCol);
    {
      aads::data::real v = 1;
      for (size_t rowID = 0; rowID < nRow; ++rowID) {
        for (auto it = myMatrix.row(rowID).begin(); it != myMatrix.row(rowID).end(); ++it) {
          *it = v;
          ++v;
        }
      }
    }

    const data::Matrix myConstMatrix = myMatrix;
    data::real v=1;
    bool testResult = true;

    for (auto it = myConstMatrix.col(0).cbegin(); it!= myConstMatrix.col(0).cend(); ++it) {
      testResult = testResult && (*it==v);
      v+=5;
    }

    data::Matrix myMatrixCol(nRow, nCol);
    {
      aads::data::real v = 1;
      for (size_t colID = 0; colID < nCol; ++colID) {
        for (auto it = myMatrixCol.col(colID).begin(); it != myMatrixCol.col(colID).end(); ++it) {
          *it = v;
          ++v;
        }
      }
    }


    if(testResult && v==31 && myMatrixCol(1,1)==8 && myMatrixCol(3,2)==16) {
      testInfo_ += testName_ + ": Passed!";
    } else {
      testInfo_ = testName_ + ": Failed!";
    }

  }

  void showResult() override {
    std::cout << testInfo_ << std::endl;
  }
};
}


#endif //ANALYTICSCORE_TEST_TEST_MATRIX_COL_ITER_H_
