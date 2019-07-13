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

inline void warning(const std::string &msg) {
  fprintf(stderr, "Warning: %s \n", msg.c_str());
}

inline void warning(bool exp, const std::string &msg) {
  if (exp) fprintf(stderr, "Warning: %s \n", msg.c_str());
}


inline void assertTrue(bool exp) {
if (!exp) error("Assert Error!");
}

inline void assertTrue(bool exp, const std::string &msg){
    if (!exp) error(msg);
}

inline void assertFalse(bool exp) {
  if (exp) error("Assert Error!");
}

inline void assertFalse(bool exp, const std::string &msg){
  if (exp) error(msg);
}

template <typename T>
inline void assertEqual(const T & a, const T & b);

template <typename T>
inline void assertEqual(const T & a, const T & b, const std::string &msg);

template <typename T>
inline void assertNotEqual(const T & a, const T & b);

template <typename T>
inline void assertNotEqual(const T & a, const T & b, const std::string &msg);

// simple class for unit test.
class Test {
 public:
  Test(const std::string &testName) : testName_{testName} {};
  virtual void doTest() = 0;
  virtual void showResult() = 0;
  virtual ~Test() = default;
 protected:
  std::string testName_;
  std::string testInfo_{};
};

}

#endif //ANALYTICSCORE_INCLUDE_UTILS_H_
