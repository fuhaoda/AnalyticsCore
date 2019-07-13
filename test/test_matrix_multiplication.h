//
// Created by Haoda Fu on 2019-07-03.
//

#ifndef ANALYTICSCORE_TEST_TEST_MATRIX_MULTIPLICATION_H_
#define ANALYTICSCORE_TEST_TEST_MATRIX_MULTIPLICATION_H_

namespace aads::test {
class TestMatrixMultiplication : public aads::utils::Test {
 public:
  TestMatrixMultiplication(const std::string &string) : Test(string) {};
  void doTest() override {

    data::Matrix A(4, 5);
    {
      aads::data::real v = 1;
      for (size_t colID = 0; colID < 5; ++colID) {
        for (auto it = A.col(colID).begin(); it != A.col(colID).end(); ++it) {
          *it = v;
          ++v;
        }
      }
    }

    data::Matrix B(5,6);
    {
      aads::data::real v = 1;
      for (size_t rowID = 0; rowID < 5; ++rowID) {
        for (auto it = B.row(rowID).begin(); it != B.row(rowID).end(); ++it) {
          *it = v;
          ++v;
        }
      }
    }

    data::Matrix C = A*B;

    if (C(0,0)==825 && C(1,0)==890 && C(1,1)==940 && C(3,4)==1260) {
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

#endif //ANALYTICSCORE_TEST_TEST_MATRIX_MULTIPLICATION_H_
