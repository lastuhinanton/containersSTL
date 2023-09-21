#include "s21_list.h"
namespace s21
{

  // List Functions

  template <typename value_type>
  list<value_type>::list() : end_(nullptr) size_(0)
  {
  }

  template <typename value_type>
  list<value_type>::list(size_type n) : end_(nullptr) size_(0)
  {
    for (size_type i = 0; i < n; ++i)
    {
      push_back(value_type());
    }
  }

  template <typename value_type>
  list<value_type>::list(std::initializer_list<value_type> const &items) : end_(nullptr), size_(0)
  {
    for (const value_type &item : items)
    {
      push_back(item);
    }
  }

  template <typename value_type>
  list<value_type>::list(const list &l) : end_(nullptr), size_(0)
  {
    for (Node *curr = l.end_->next_; curr != nullptr; curr = curr->next_)
    {
      push_back(curr->data_);
    }
  }

  template <typename value_type>
  list<value_type>::list(list &&l) : end_(l.end_), size_(l.size_)
  {
    l.end_ = nullptr;
    l.size_ = 0;
  }

  template <typename value_type>
  list<value_type>::~list()
  {
    clear();
    delete end_;
  }

  template <typename value_type>
  typename list<value_type>::list &list<value_type>::operator=(list &&l)
  {
    if (this != &l)
    {
      clear();
      swap(l);
    }
    return *this;
  }

  // List Element access
  template <typename value_type>
  typename list<value_type>::const_reference list<value_type>::front() const {
    if (empty()){
      throw std::out_of_range("list is empty");
    } else {
      return end_->next_->data_;
    }
  }

  template <typename value_type>
  typename list<value_type>::const_reference list<value_type>::back() const {
    if (empty()) {
      throw std::out_of_range("list is empty");
    } else {
      return end_->data;
    }
  }

  // List Capacity

  template <typename value_type>
  bool list<value_type>::empty() const
  {
    return size_ == 0;
  }

  template <typename value_type>
  typename list<value_type>::size_type list<value_type>::size()
  {
    return size_;
  }

  template <typename value_type>
  typename list<value_type>::size_type list<value_type>::max_size()
  {
    return std::numeric_limits<size_type>::max();
  }

  template <typename value_type>
  void list<value_type>::push_back(const_reference value)
  {
    Node *new_node = new Node(value);
    if (empty())
    {
      head_ = new_node;
      tail_ = new_node;
    }
    else
    {
      new_node->prev_ = tail_;
      tail_->next_ = new_node;
      tail_ = new_node;
    }
    size_++;
  }

  template <typename value_type>
  void list<value_type>::push_front(const_reference value)
  {
    Node *new_node = new Node(value);
    if (empty())
    {
      head_ = new_node;
      tail_ = new_node;
    }
    else
    {
      new_node->next_ = head_;
      head_->prev = new_node;
      head_ = new_node;
    }
    size_++;
  }

  template <typename value_type>
  void list<value_type>::pop_back()
  {
    if (head_ == nullptr)
    {
      throw std::out_of_range("list is empty");
    }
    else
    {
      Node *node_to_delete = tail_;
      tail_ = tail_->prev_;
      if (head_ != nullptr)
      {
        tail_->next_ = nullptr;
      }
      else
      {
        head_ = nullptr;
        delete node_to_delete;
        size--;
      }
    }
  }

  template <typename value_type>
  void list<value_type>::pop_front()
  {
    if (tail_ == nullptr)
    {
      throw std::out_of_range("list is empty");
    }
    else
    {
      Node *node_to_delete = head_;
      head_ = head_->next_;
      if (tail_ != nullptr)
      {
        head_->perv_ = nullptr;
      }
      else
      {
        tail_ = nullptr;
        delete node_to_delete;
        size--;
      }
    }
  }

  // List Modifiers

  template <typename value_type>
  void list<value_type>::clear()
  {
    while (!empty())
    {
      pop_back();
    }
  }
  //   iterator insert(iterator pos, const_reference value);
  //   void erase(iterator pos);

  template <typename value_type>
  void list<value_type>::swap(list &other)
  {
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }
  // void merge(list &other);
  //   void splice(const_iterator pos, list& other);
  //   void reverse();
  //   void unique();
  //  void sort();

}