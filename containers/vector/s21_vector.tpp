#include "s21_vector.h"

namespace s21 {

    // main contstructors
    template <class value_type>
    vector<value_type>::vector() { this->NullVector(); }

    template <class value_type>
    vector<value_type>::vector(size_type n) { this->InitVector(n); }
    
    template <class value_type>
    vector<value_type>::vector(std::initializer_list<value_type> const &items) {
      size_ = capacity_ = items.size();
      vector_ = new value_type[size_];
      std::copy(items.begin(), items.end(), vector_);
    }

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
    typename vector<value_type>::size_type vector<value_type>::size() const {
        return size_;
    }

    template <class value_type>
    typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
      if (pos >= size()) { throw std::out_of_range("[at]: out of range"); }
      return vector_[pos];
    }

}