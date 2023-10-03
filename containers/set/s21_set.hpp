#include "s21_set.h"
namespace s21 {
template <class value_type>
set<value_type>::set() {}

template <class value_type>
set<value_type>::set(std::initializer_list<value_type> const& items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    AddItem(*it);
  }
}

template <class value_type>
set<value_type>::set(const set& s) {
  *this = s;
}

template <class value_type>
set<value_type>& set<value_type>::operator=(const set& s) {
  if (this == &s) {
    return *this;
  }
  tree_ = s.tree_;
  return *this;
}

template <class value_type>
set<value_type>::set(set&& s) noexcept {
  *this = std::move(s);
}

template <class value_type>
set<value_type>& set<value_type>::operator=(set&& s) {
  tree_.clear();
  if (this == &s) return *this;
  tree_ = std::move(s.tree_);
  return *this;
}
template <class value_type>
set<value_type>::~set() {
  tree_.clear();
  if (end_ != nullptr) delete end_;
}

template <class value_type>
void set<value_type>::AddItem(value_type arg) {
  tree_.insert(arg, arg);
}

template <class value_type>
pair<SetIterator<value_type>, bool> set<value_type>::insert(value_type key) {
  bool _exist = false;
  set::node_pointer pointer = tree_.search(key);
  if (pointer == nullptr) {
    _exist = true;
    AddItem(key);
    pointer = tree_.search(key);
  }
  pair<set::iterator, bool> item;
  set::iterator it(pointer, nullptr);
  item.first = it;
  item.second = _exist;
  return item;
}

template <class value_type>
void set<value_type>::merge(set& other) {
  for (auto item : other) {
    AddItem(item);
  }
  other.clear();
}

template <class value_type>
void set<value_type>::swap(set& other) {
  set<value_type> temp = std::move(other);
  other = std::move(*this);
  *this = std::move(temp);
}

template <class value_type>
void set<value_type>::erase(const key_type& value) {
  tree_.remove(value);
}

template <class value_type>
void set<value_type>::erase(set::iterator pos) {
  if (pos != end()) tree_.remove(*pos);
}

template <class value_type>
template <typename... Args>
std::vector<pair<SetIterator<value_type>, bool>> set<value_type>::insert_many(
    Args&&... args) {
  std::vector<pair<set::iterator, bool>> result;
  ((result.emplace_back(insert(std::forward<Args>(args))), ...));
  return result;
}

template <class value_type>
bool set<value_type>::empty() {
  return tree_.get_root_pointer() == nullptr;
}

template <class value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return tree_.get_size();
}

template <class value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  size_type _set_size = sizeof(node_type);
  return (std::numeric_limits<size_type>::max() / _set_size) - size();
}
template <class value_type>
void set<value_type>::clear() {
  tree_.clear();
}

template <class value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  node_pointer pointer = tree_.begin();
  iterator it(pointer, tree_.get_reference_of_size());
  return it;
}
template <class value_type>
typename set<value_type>::iterator set<value_type>::end() {
  node_pointer pointer = tree_.end();
  if (pointer == nullptr) return iterator(nullptr, nullptr);
  end_->next = pointer;
  end_->key = pointer->key;
  end_->prev = pointer;
  iterator it(end_, nullptr);
  return it;
}

template <class value_type>
typename set<value_type>::iterator set<value_type>::find(
    const key_type& value) {
  node_pointer pointer = tree_.search(value);
  if (pointer == nullptr) return end();
  return iterator(pointer, tree_.get_reference_of_size());
}

template <class value_type>
bool set<value_type>::contains(const key_type& key) {
  return tree_.search(key) != nullptr;
}
}  // namespace s21