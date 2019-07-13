//
// Created by Haoda Fu on 2019-06-27.
//

#include <iostream>

#include "date_time.h"
#include "utils.h"
#include "test_matrix_row_iter.h"
#include "test_matrix_col_iter.h"
#include "test_matrix_multiplication.h"

int main() {
  double x1 = aads::dateTime::getTime();

  std::vector<aads::utils::Test *> unitTests;

  auto testMatrixRowIter = aads::test::TestMatrixRowIter("Test Matrix Row Iter");
  unitTests.push_back(&testMatrixRowIter);

  auto testMatrixColIter = aads::test::TestMatrixColIter("Test Matrix Col Iter");
  unitTests.push_back(&testMatrixColIter);

  auto testMatrixMultiplication = aads::test::TestMatrixMultiplication("Test Matrix Multiplication");
  unitTests.push_back(&testMatrixMultiplication);



  for(auto const & item: unitTests){
    item -> doTest();
    item->showResult();
  }


  std::cout << aads::dateTime::getTime() - x1 << std::endl;


  return 0;
}