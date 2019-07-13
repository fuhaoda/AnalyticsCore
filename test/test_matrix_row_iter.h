//
// Created by Haoda Fu on 2019-07-02.
//

#include "utils.h"
#include "matrix.h"
#include "iterator.h"
#include <iostream>

#ifndef ANALYTICSCORE_TEST_TEST_MATRIX_ROW_ITER_H_
#define ANALYTICSCORE_TEST_TEST_MATRIX_ROW_ITER_H_

namespace aads::test {
class TestMatrixRowIter : public aads::utils::Test {
 public:
  TestMatrixRowIter(const std::string &string) : Test(string) {};
  void doTest() override {
    data::Matrix myMatrix(5u, 5u);
    {
      aads::data::real v = 1;
      for (size_t rowID = 0; rowID < 5; ++rowID) {
        for (auto it = myMatrix.row(rowID).begin(); it != myMatrix.row(rowID).end(); ++it) {
          *it = v;
          ++v;
        }
      }
    }
    const data::Matrix myConstMatrix = myMatrix;
    if (myConstMatrix(0, 0) == 1 && myConstMatrix(1, 1) == 7 && myConstMatrix(4, 4) == 25) {
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

#endif //ANALYTICSCORE_TEST_TEST_MATRIX_ROW_ITER_H_
