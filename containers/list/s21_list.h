#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list;

template <typename T>
struct Node {
  T value_;
  Node<T> *prev_;
  Node<T> *next_;

  Node(const T &value) : value_(value), prev_(nullptr), next_(nullptr) {}
  Node() : value_(), prev_(nullptr), next_(nullptr) {}
};

template <typename T>
class ListIterator {
 public:
  //  List Member type
  using value_type = T;
  using reference = T &;
  using iterator = ListIterator<T>;
  using size_type = std::size_t;
  friend class list<T>;

  ListIterator() { ptr_ = nullptr; }
  ListIterator(Node<T> *ptr) : ptr_(ptr){};

  reference operator*() {
    if (!this->ptr_) {
      throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
  }

  ListIterator operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
  }

  ListIterator operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
  }

  ListIterator &operator++() {
    ptr_ = ptr_->next_;
    return *this;
  }

  ListIterator &operator--() {
    ptr_ = ptr_->prev_;
    return *this;
  }

  ListIterator operator+(const size_type value) {
    Node<T> *tmp = ptr_;
    for (size_type i = 0; i < value; i++) {
      tmp = tmp->next_;
    }

    ListIterator res(tmp);
    return res;
  }

  ListIterator operator-(const size_type value) {
    Node<T> *tmp = ptr_;
    for (size_type i = 0; i < value; i++) {
      tmp = tmp->prev_;
    }
    ListIterator res(tmp);
    return res;
  }

  bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }
  bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

 private:
  Node<T> *ptr_ = nullptr;
};

template <typename T>
class ListConstIterator : public ListIterator<T> {
 public:
  friend class list<T>;
  using iterator = ListIterator<T>;
  using reference = T &;
  using const_iterator = ListConstIterator<T>;

  ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
  const T &operator*() { return ListIterator<T>::operator*(); }

  ListConstIterator &operator++() {
    ptr_ = ptr_->next_;
    return *this;
  }

  ListConstIterator &operator--() {
    ptr_ = ptr_->prev_;
    return *this;
  }

  bool operator==(ListConstIterator other) { return this->ptr_ == other.ptr_; }
  bool operator!=(ListConstIterator other) { return this->ptr_ != other.ptr_; }

 private:
  Node<T> *ptr_ = nullptr;
};

template <typename T>
class list {
 public:
  //  List Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 private:
  Node<T> *end_;
  size_type size_;

 public:
  //  List Functions
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);
  list &operator=(const list &other);

  // List Element access
  const_reference front();
  const_reference back();

  // List Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size();

  // List Modifiers
  void clear();
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void reverse();
  void unique();
  void sort();

  //  List Member type
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  // List Iterators
  iterator begin() const;
  iterator end() const;
  // const_iterator begin() const;
  // const_iterator end() const;

  // List Modifiers
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void splice(const_iterator pos, list &other);

 private:
  // Support
  void initialization();
  void quick_sort(iterator first, iterator last);
};

}  // namespace s21

#endif  // S21_LIST_H
