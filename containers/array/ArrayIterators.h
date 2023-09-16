#ifndef S21_ITERATORS_H
#define S21_ITERATORS_H

namespace s21 {

template <class T>
class ArrayIterator {
  friend class array<T>;
  friend class ArrayConstIterator<T>;

  public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    ArrayIterator();
    ArrayIterator(pointer ptr);

    pointer operator&();
    reference operator*();
    ArrayIterator& operator+(int n);
    ArrayIterator& operator++();
    ArrayIterator& operator--();
    bool operator==(const ArrayIterator n);
    bool operator!=(const ArrayIterator n);


  private:
    pointer ptr_;
};

template <class T>
class ArrayConstIterator {
  friend class array<T>;
  friend class ArrayIterator<T>;

  public:
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    ArrayConstIterator() { ptr_ = nullptr; }
    ArrayConstIterator(pointer ptr);

    pointer operator&();
    reference operator*();
    ArrayConstIterator& operator+(int n);
    ArrayConstIterator& operator++();
    ArrayConstIterator& operator--();
    bool operator==(const ArrayConstIterator n);
    bool operator!=(const ArrayConstIterator n);

  private:
    pointer ptr_;

};

}
#endif // S21_ITERATORS_H
