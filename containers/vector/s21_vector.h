#ifndef S21_VECTOR_H
#define S21_VECTOR_H

namespace s21 {

#include "VectorIterators.h"

template <class T>
class S21Vector {
  public:
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type&;
    using iterator = IteratorVector<value_type>;
    using const_iterator = ConstIteratorVector<value_type>;
    using size_type = std::size_t;

  private:

};

}
#endif // S21_VECTOR_H
