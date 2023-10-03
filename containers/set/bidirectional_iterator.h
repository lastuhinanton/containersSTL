#ifndef _THIS_IS_TEST_
#define _THIS_IS_TEST_

template <class T>
class SetIterator {
 public:
  using key_type = T;
  using value_type = key_type;
  using pointer_type = Node<key_type, value_type>*;
  using reference_type = Node<key_type, value_type>&;
  using size_type = size_t;

 public:
  SetIterator(){};
  ~SetIterator() {
    if (end_ != nullptr) {
      delete end_;
    }
  };
  SetIterator(const SetIterator& other) {
    ptr_ = other.ptr_;
    size_ = other.size_;
  }
  SetIterator(pointer_type ptr, size_type* size) : ptr_(ptr), size_(size){};

  bool operator!=(const SetIterator& ptr) {
    if (ptr_ == nullptr) return false;
    return !(*this == ptr);
  }

  SetIterator operator=(const SetIterator& it) {
    if (end_ != nullptr) {
      delete end_;
    }
    this->ptr_ = nullptr;
    this->size_ = nullptr;
    if (this == &it) {
      return *this;
    }
    ptr_ = it.ptr_;
    size_ = it.size_;
    return *this;
  }
  bool operator==(const SetIterator& ptr) {
    return (this->ptr_->next == ptr.ptr_->next) &&
           (this->ptr_->key == ptr.ptr_->key);
  }
  SetIterator& operator--(int) {
    if (ptr_ == nullptr) return *this;
    if (ptr_->prev != nullptr) ptr_ = ptr_->prev;
    return *this;
  }
  SetIterator& operator++(int) {
    if (ptr_ == nullptr) return *this;

    if (ptr_->next == nullptr) {
      end_ = new Node<key_type, value_type>;
      end_->next = ptr_;
      end_->prev = ptr_;
      end_->key = ptr_->key;
      ptr_ = end_;
    } else {
      ptr_ = ptr_->next;
    }
    return *this;
  }

  SetIterator operator++() {
    SetIterator it = *this;
    (*this)++;
    return it;
  }

  SetIterator operator--() {
    SetIterator it = *this;
    (*this)--;
    return it;
  }

  key_type operator*() const {
    if (ptr_ != nullptr) return ptr_->key;
    return 0;
  }

  size_type get_size() { return *size_; }

 private:
  pointer_type ptr_;
  size_type* size_;
  pointer_type end_ = nullptr;
};

#endif  //_THIS_IS_TEST_