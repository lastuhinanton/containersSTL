#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <cmath>
#include <iostream>

namespace s21 {

template <class T>
class IteratorVector;

template <class T>
class ConstIteratorVector;

template <class T>
class s21vector {
  public:
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type&;
    using iterator = IteratorVector<value_type>;
    using const_iterator = ConstIteratorVector<value_type>;
    using size_type = std::size_t;

    s21vector() { std::cout << "Hello world!" << std::endl; }

  private:
    size_type size_;
    size_type capacity_;
    value_type *container_;


};

#include "VectorIterators.h"

}
#endif // S21_VECTOR_H
