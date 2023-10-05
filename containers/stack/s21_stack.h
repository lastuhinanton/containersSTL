#ifndef S21_STACK_H
#define S21_STACK_H

#include "../list/s21_list.h" 

namespace s21 {

template <typename T>
class stack {
 public:

 // Stack Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  // Stack Member functions
  stack() { data_.clear(); }

  stack(std::initializer_list<value_type> const &items) {
    data_.clear();
    for (const auto &i : items) {
      push(i);
    }
  }

  stack(const stack &s) { operator=(s); }

  stack(stack &&s) { operator=(std::move(s)); }

  ~stack() { data_.clear(); }

  stack &operator=(stack &&s) {
    data_ = std::move(s.data_);
    return *this;
  }

  stack &operator=(const stack &s) {
    data_ = s.data_;
    return *this;
  }

  // Stack Element access
  const_reference top() { return data_.front(); }

  // Stack Capacity
  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  // Stack Modifiers
  void push(const_reference value) { data_.push_front(value); }
  void pop() { data_.pop_front(); }
  void swap(stack &other) { data_.swap(other.data_); }

 private:
  list<T> data_;
};
} 

#endif // S21_STACK_H
