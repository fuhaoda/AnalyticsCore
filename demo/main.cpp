//
// Created by Haoda Fu on 2019-06-19.
//

#include <iostream>

#include "date_time.h"

int main() {
  double x1 = aads::dateTime::getTime();

  std::cout << aads::dateTime::getTime() - x1 << std::endl;

  return 0;
}