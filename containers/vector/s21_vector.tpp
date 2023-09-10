#include "s21_vector.h"

namespace s21 {

    // Vector Member functions
    template <class value_type>
    vector<value_type>::vector() { NullVector(); }

    template <class value_type>
    vector<value_type>::vector(size_type n) { InitVector(n); }
    
    template <class value_type>
    vector<value_type>::vector(std::initializer_list<value_type> const &items) {
      size_ = capacity_ = items.size();
      vector_ = new value_type[size_];
      std::copy(items.begin(), items.end(), vector_);
    }

    template <class value_type>
    vector<value_type>::vector(const vector &v) { CopyVector(v); }

    // template <class value_type>
    // vector<value_type>::vector(const vector &v) {
    //   InitVector(v.size());
    //   std::copy(v.begin(), v.end(), vector_);
    // }

    template <class value_type>
    vector<value_type>::~vector() { DeleteVector(); }


    // My own functions
    template <class value_type>
    void vector<value_type>::NullVector() {
        size_ = 0;
        capacity_ = 0;
        vector_ = nullptr;
    };

    template <class value_type>
    void vector<value_type>::InitVector(size_type n) {
      size_ = n;
      capacity_ = n;
      vector_ = new value_type[n];
    };

    template <class value_type>
    void vector<value_type>::DeleteVector() {
      if (vector_ != nullptr) {
        delete[] vector_;
      }
      NullVector();
    };

    template <class value_type>
    void vector<value_type>::CopyVector(const vector &v) {
      size_type cursize = v.size();
      InitVector(cursize);
      for (size_type i = 0; i < cursize; i++) {
        vector_[i] = v.vector_[i];
      }
    };

    template <class value_type>
    bool vector<value_type>::operator==(const vector &v) {
      size_type cursize = size();
      bool flag = true;
      if (cursize != v.size()) flag = false;
      for (size_type i = 0; i < cursize && flag; i++) {
        if (vector_[i] != v.vector_[i]) flag = false;
      }
      return flag;
    }


    // Vector Capacity
    template <class value_type>
    bool vector<value_type>::empty() const {
      return size() == 0;
    }

    template <class value_type>
    typename vector<value_type>::size_type vector<value_type>::size() const {
        return size_;
    }

    template <class value_type>
    typename vector<value_type>::size_type vector<value_type>::max_size() const {
      return std::numeric_limits<size_type>::max() / sizeof(size_type);
    }

    // template <class value_type>
    // void vector<value_type>::reserve(size_type size) {
    //   vector<value_type> new
    // }


    // Vector Element access
    template <class value_type>
    typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
      if (pos >= size()) { throw std::out_of_range("[at]: out of range"); }
      return vector_[pos];
    }

    template <class value_type>
    typename vector<value_type>::reference vector<value_type>::operator[](size_type pos) {
      return at(pos);
    }


    // Vector Iterators
    template <class value_type>
    typename vector<value_type>::iterator vector<value_type>::begin() {
      return iterator(vector_);
    }

    template <class value_type>
    typename vector<value_type>::iterator vector<value_type>::end() {
      return iterator(vector_ + size_ + 1);
    }


    // Vector Modifiers


}