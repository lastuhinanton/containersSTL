#ifndef S21_ITERATORS_H
#define S21_ITERATORS_H

namespace s21 {

template <typename T>
class IteratorVector {
  friend class vector<T>;
  friend class ConstIteratorVector<T>;

  public:

  private:

};

template <typename T>
class ConstIteratorVector {
  friend class vector<T>;
  friend class IteratorVector<T>;

  public:

  private:

};

}
#endif // S21_ITERATORS_H
