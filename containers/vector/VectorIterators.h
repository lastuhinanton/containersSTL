#ifndef S21_ITERATORS_H
#define S21_ITERATORS_H

namespace s21 {

template <class T>
class VectorIterator {
  friend class vector<T>;
  friend class VectorConstIterator<T>;

  public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    VectorIterator();
    VectorIterator(pointer ptr);

    reference operator*();
    VectorIterator& operator+(int n);
    VectorIterator& operator++();
    VectorIterator& operator--();
    bool operator==(VectorIterator n);
    bool operator!=(VectorIterator n);


  private:
    pointer ptr_;
};

template <class T>
class VectorConstIterator {
  friend class vector<T>;
  friend class VectorIterator<T>;

  public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    VectorConstIterator() { ptr_ = nullptr; }

  private:
    pointer ptr_;

};

}
#endif // S21_ITERATORS_H
