#include "VectorIterators.h"

namespace s21 {
    template <class value_type>
    VectorIterator<value_type>::VectorIterator() { ptr_ = nullptr; }

    template <class value_type>
    VectorIterator<value_type>::VectorIterator(pointer ptr) { ptr_ = ptr; }

    template <class value_type>
    typename VectorIterator<value_type>::reference VectorIterator<value_type>::operator*() { return *ptr_; }

    template <class value_type>
    typename VectorIterator<value_type>::pointer VectorIterator<value_type>::operator&() { return ptr_; }
    
    template <class value_type>
    VectorIterator<value_type>& VectorIterator<value_type>::operator+(int n) {
        ptr_ = ptr_ + n;
        return *this;
    }
    
    template <class value_type>
    VectorIterator<value_type>& VectorIterator<value_type>::operator++() {
        ++ptr_;
        return *this;
    }
    
    template <class value_type>
    VectorIterator<value_type>& VectorIterator<value_type>::operator--() {
        --ptr_;
        return *this;
    }

    template <class value_type>
    bool VectorIterator<value_type>::operator==(const VectorIterator n) { return ptr_ == n.ptr_; }

    template <class value_type>
    bool VectorIterator<value_type>::operator!=(const VectorIterator n) { return ptr_ != n.ptr_; }

}