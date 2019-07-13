//
// Created by Haoda Fu on 2019-07-02.
//

#include "iterator.h"

aads::data::Iterator aads::data::IteratorFactory::begin() {
  return Iterator(begin_, stride_);
}

aads::data::Iterator aads::data::IteratorFactory::end() {
  return Iterator(end_, stride_);
}

aads::data::ConstIterator aads::data::IteratorFactory::cbegin() {
  return ConstIterator(cbegin_, stride_);
}
aads::data::ConstIterator aads::data::IteratorFactory::cend() {
  return ConstIterator(cend_, stride_);
}
aads::data::Iterator aads::data::IteratorFactory::rbegin() {
  return aads::data::Iterator(end_-stride_, -stride_);
}

aads::data::Iterator aads::data::IteratorFactory::rend() {
  return aads::data::Iterator(begin_-stride_, -stride_);
}

aads::data::ConstIterator aads::data::IteratorFactory::crbegin() {
  return aads::data::ConstIterator(cend_-stride_, -stride_);
}
aads::data::ConstIterator aads::data::IteratorFactory::crend() {
  return aads::data::ConstIterator(cbegin_-stride_, -stride_);
}

bool aads::data::Iterator::operator==(const aads::data::Iterator &rhs) const {
  return curr_ == rhs.curr_;
}

bool aads::data::Iterator::operator!=(const aads::data::Iterator &rhs) const {
  return curr_ != rhs.curr_;
}

aads::data::Iterator &aads::data::Iterator::operator++() {
  curr_ += stride_;
  return *this;
}

aads::data::real &aads::data::Iterator::operator*() {
  return *curr_;
}

bool aads::data::ConstIterator::operator==(const aads::data::ConstIterator &rhs) const {
  return curr_ == rhs.curr_;
}
bool aads::data::ConstIterator::operator!=(const aads::data::ConstIterator &rhs) const {
  return curr_ != rhs.curr_;
}

aads::data::ConstIterator &aads::data::ConstIterator::operator++() {
  curr_ += stride_;
  return *this;
}
const aads::data::real &aads::data::ConstIterator::operator*() {
  return *curr_;
}








