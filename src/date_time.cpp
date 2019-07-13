//
// Created by Haoda Fu on 2019-06-19.
//

#include "date_time.h"

double aads::dateTime::getTime() {
  return std::chrono::duration<double>(
      std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}