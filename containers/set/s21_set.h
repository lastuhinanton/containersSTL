#ifndef S21_SET_H
#define S21_SET_H

#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

#include "../tree/avlTree.h"
#include "bidirectional_iterator.h"

namespace s21 {
template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

template <class T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = SetIterator<T>;
  using const_iterator = iterator;
  using node_type = Node<T, T>;
  using node_pointer = node_type*;
  using size_type = size_t;

 public:
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set& operator=(const set& s);
  set(set&& s) noexcept;
  set& operator=(set&& s);
  ~set();

 public:
  template <typename... Args>
  std::vector<pair<iterator, bool>> insert_many(Args&&... args);
  //   s21::vector<pair<iterator, bool>> insert_many(Args&&... args);

  bool empty();
  void clear();
  iterator end();
  iterator begin();
  size_type size();
  size_type max_size();
  void swap(set& other);
  void merge(set& other);
  void erase(iterator pos);
  void erase(const key_type& value);
  bool contains(const key_type& key);
  iterator find(const key_type& value);
  pair<iterator, bool> insert(key_type key);

 private:
  AVLTree<key_type, value_type> tree_;
  node_pointer end_ = new node_type;
  void AddItem(value_type arg);
};
}  // namespace s21
#include "s21_set.hpp"
#endif  // S21_SET_H