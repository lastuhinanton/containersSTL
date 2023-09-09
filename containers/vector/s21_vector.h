#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <cmath>
#include <iostream>

namespace s21 {

template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

template <class T>
class vector {
  public:
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = VectorIterator<value_type>;
    using const_iterator = VectorConstIterator<value_type>;
    using size_type = std::size_t;

    vector();
    vector(size_type n);
    vector(std::initializer_list<value_type> const &items);

    // vector(const vector &v);
    // vector(vector &&v);
    // ~vector();

    // vector operator=(vector &&v);

    size_type size() const;
    reference at(size_type pos);

    

  private:
    size_type size_;
    size_type capacity_;
    value_type *vector_;
    void NullVector();
    void InitVector(size_type n);


};

#include "VectorIterators.h"

}

#include "s21_vector.tpp"
#endif // S21_VECTOR_H
