#ifndef S21_ITERATORS_H
#define S21_ITERATORS_H

namespace s21 {

    

template <typename T>
class IteratorVector {
  friend class s21vector<T>;
  friend class ConstIteratorVector<T>;

  public:
    using value_type = T;
    using ptr = value_type*;
    using reference = value_type&;

    IteratorVector() { ptr_ = nullptr; }

  private:
    ptr ptr_;
};

template <typename T>
class ConstIteratorVector {
  friend class s21vector<T>;
  friend class IteratorVector<T>;

  public:
    using value_type = T;
    using ptr = value_type*;
    using reference = value_type&;

    ConstIteratorVector() { ptr_ = nullptr; }

  private:
    ptr ptr_;

};

}
#endif // S21_ITERATORS_H
