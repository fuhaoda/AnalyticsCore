//
// Created by Haoda Fu on 2019-07-03.
//

#ifndef ANALYTICSCORE_TEST_TEST_TEMPLATE_H_
#define ANALYTICSCORE_TEST_TEST_TEMPLATE_H_

namespace aads::test {
class TestName : public aads::utils::Test {
 public:
  TestName(const std::string &string) : Test(string) {};
  void doTest() override {

    if (1+1==2) {
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


#endif //ANALYTICSCORE_TEST_TEST_TEMPLATE_H_
