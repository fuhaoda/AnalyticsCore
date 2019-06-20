//
// Created on 2019-06-01.
//

#ifndef ANALYTICSCORE_INCLUDE_UTILS_H_
#define ANALYTICSCORE_INCLUDE_UTILS_H_

#include <iostream>

namespace aads::utils {

inline void error(const std::string &msg) {
  fprintf(stderr, "Error: %s\n", msg.c_str());
  exit(-1);
}

inline void assert(bool exp) {
if (!exp) error("Assert Error!");
}

inline void assert(bool exp, const std::string &msg){
    if (!exp) error(msg);
}

inline void warning(const std::string &msg) {
  fprintf(stderr, "Warning: %s \n", msg.c_str());
}

inline void warning(bool exp, const std::string &msg) {
  if (exp) fprintf(stderr, "Warning: %s \n", msg.c_str());
}
}

#endif //ANALYTICSCORE_INCLUDE_UTILS_H_
