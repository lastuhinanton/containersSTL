#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../list/s21_list.h"

namespace s21
{

  template <typename T>
  class queue
  {
  public:
    // Queue Member type
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t;

    // Queue Member functions
    queue() { data_.clear(); }

    queue(std::initializer_list<value_type> const &items)
    {
      data_.clear();
      for (const auto &i : items)
      {
        push(i);
      }
    }

    queue(const queue &q) { operator=(q); }

    queue(queue &&q) { operator=(std::move(q)); }

    ~queue() { data_.clear(); }

    queue &operator=(queue &&q)
    {
      this->data_ = std::move(q.data_);
      return *this;
    }

    queue &operator=(const queue &q)
    {
      this->data_ = q.data_;
      return *this;
    }

    // Queue Element access
    const_reference front() { return data_.front(); }
    const_reference back() { return data_.back(); }

    // Queue Capacity
    bool empty() const { return data_.empty(); }
    size_type size() const { return data_.size(); }

    // Queue Modifiers
    void push(const_reference value) { data_.push_back(value); }
    void pop() { data_.pop_front(); }
    void swap(queue &other) { data_.swap(other.data_); }

  private:
    list<T> data_;
  };

}

#endif // S21_QUEUE_H
