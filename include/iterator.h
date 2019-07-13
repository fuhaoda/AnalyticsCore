//
// Created by Haoda Fu on 2019-07-02.
//


#include "matrix.h"

#ifndef ANALYTICSCORE_INCLUDE_ITERATOR_H_
#define ANALYTICSCORE_INCLUDE_ITERATOR_H_

#include "base.h"

namespace aads::data {

class Iterator {
 public:
  Iterator(real *curr, size_t stride) : curr_{curr}, stride_{stride} {};
  bool operator==(const Iterator &rhs) const;
  Iterator &operator++();
  bool operator!=(const Iterator &rhs) const;
  real &operator*();
 private:
  size_t stride_;
  real *curr_;
};

class ConstIterator {
 public:
  ConstIterator(const real *curr, size_t stride) : curr_{curr}, stride_{stride} {};
  bool operator==(const ConstIterator &rhs) const;
  ConstIterator &operator++();
  bool operator!=(const ConstIterator &rhs) const;
  const real &operator*();
 private:
  size_t stride_;
  const real *curr_;
};

class IteratorFactory {
 public:
  IteratorFactory(real *begin, real *end, size_t stride) : begin_{begin}, end_{end}, stride_{stride} {};
  IteratorFactory(const real *begin, const real *end, size_t stride) : cbegin_{begin}, cend_{end}, stride_{stride} {};

  Iterator begin();
  Iterator end();
  ConstIterator cbegin();
  ConstIterator cend();

  Iterator rbegin();
  Iterator rend();
  ConstIterator crbegin();
  ConstIterator crend();
 private:
  real *begin_{nullptr};
  real *end_{nullptr};
  const real *cbegin_{nullptr};
  const real *cend_{nullptr};
  size_t stride_{1};
};

} // namespace aads::data
#endif //ANALYTICSCORE_INCLUDE_ITERATOR_H_
