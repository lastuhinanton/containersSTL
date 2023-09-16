#include "s21_array.h"

namespace s21 {

    // array Member functions
    template <class value_type>
    array<value_type>::array() { NullArray(); }

    template <class value_type>
    array<value_type>::array(size_type n) { InitArray(n); }
    
    template <class value_type>
    array<value_type>::array(std::initializer_list<value_type> const &items) {
      size_ = items.size();
      array_ = new value_type[size_];
      std::copy(items.begin(), items.end(), array_);
    }

    template <class value_type>
    array<value_type>::array(const array &v) {
      InitArray(v.size());
      CopyArray(v);
    }

    template <class value_type>
    array<value_type>::array(array &&v) { MoveArray(std::move(v)); }

    template <class value_type>
    array<value_type>::~array() { DeleteArray(); }

    template <class value_type>
    array<value_type> array<value_type>::operator=(array &&v) {
      DeleteArray();
      MoveArray(std::move(v));
      return *this;
    }


    // My own functions
    template <class value_type>
    void array<value_type>::NullArray() {
        size_ = 0;
        array_ = nullptr;
    };

    template <class value_type>
    void array<value_type>::InitArray(size_type n) {
      size_ = 0;
      array_ = new value_type[n];
    };

    template <class value_type>
    void array<value_type>::DeleteArray() {
      if (array_ != nullptr) {
        delete[] array_;
      }
      NullArray();
    };

    template <class value_type>
    void array<value_type>::CopyArray(const array &v) {
      size_ = v.size();
      for (size_type i = 0; i < size_; i++) {
        array_[i] = v.array_[i];
      }
    };

    template <class value_type>
    void array<value_type>::MoveArray(array &&v) {
      size_ = v.size_;
      array_ = v.array_;
      v.NullArray();
    }

    template <class value_type>
    bool array<value_type>::operator==(const array &v) {
      size_type cursize = size();
      bool flag = true;
      if (cursize != v.size()) flag = false;
      for (size_type i = 0; i < cursize && flag; i++) {
        if (array_[i] != v.array_[i]) flag = false;
      }
      return flag;
    }


    // array
    template <class value_type>
    bool array<value_type>::empty() const {
      return size() == 0;
    }

    template <class value_type>
    typename array<value_type>::size_type array<value_type>::size() const {
        return size_;
    }

    template <class value_type>
    typename array<value_type>::size_type array<value_type>::max_size() const {
      return std::numeric_limits<size_type>::max() / sizeof(size_type);
    }

    // array Element access
    template <class value_type>
    typename array<value_type>::reference array<value_type>::at(size_type pos) {
      if (pos >= size()) { throw std::out_of_range("[at]: out of range"); }
      return array_[pos];
    }

    template <class value_type>
    typename array<value_type>::reference array<value_type>::operator[](size_type pos) {
      return at(pos);
    }

    template <class value_type>
    typename array<value_type>::const_reference array<value_type>::front() {
      return *(begin());
    }

    template <class value_type>
    typename array<value_type>::const_reference array<value_type>::back() {
      return *(--end());
    }

    template <class value_type>
    typename array<value_type>::pointer array<value_type>::data() {
      return array_;
    }


    // array Iterators
    template <class value_type>
    typename array<value_type>::iterator array<value_type>::begin() {
      return iterator(array_);
    }

    template <class value_type>
    typename array<value_type>::iterator array<value_type>::end() {
      return iterator(array_ + size_);
    }

    template <class value_type>
    void array<value_type>::swap(array& other) {
      array<value_type> temp(size_);
      temp.CopyArray(*this);
      DeleteArray();
      InitArray(other.size_);
      CopyArray(other);
      other.DeleteArray();
      other.InitArray(temp.size_);
      other.CopyArray(temp);
    }

}