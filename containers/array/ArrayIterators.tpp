#include "VectorIterators.h"

namespace s21 {
    template <class value_type>
    ArrayIterator<value_type>::ArrayIterator() { ptr_ = nullptr; }

    template <class value_type>
    ArrayIterator<value_type>::ArrayIterator(pointer ptr) { ptr_ = ptr; }

    template <class value_type>
    typename ArrayIterator<value_type>::reference ArrayIterator<value_type>::operator*() { return *ptr_; }

    template <class value_type>
    typename ArrayIterator<value_type>::pointer ArrayIterator<value_type>::operator&() { return ptr_; }
    
    template <class value_type>
    ArrayIterator<value_type>& ArrayIterator<value_type>::operator+(int n) {
        ptr_ = ptr_ + n;
        return *this;
    }
    
    template <class value_type>
    ArrayIterator<value_type>& ArrayIterator<value_type>::operator++() {
        ++ptr_;
        return *this;
    }
    
    template <class value_type>
    ArrayIterator<value_type>& ArrayIterator<value_type>::operator--() {
        --ptr_;
        return *this;
    }

    template <class value_type>
    bool ArrayIterator<value_type>::operator==(const ArrayIterator n) { return ptr_ == n.ptr_; }

    template <class value_type>
    bool ArrayIterator<value_type>::operator!=(const ArrayIterator n) { return ptr_ != n.ptr_; }

}

namespace s21 {
    template <class value_type>
    ArrayConstIterator<value_type>::ArrayConstIterator() { ptr_ = nullptr; }

    template <class value_type>
    ArrayConstIterator<value_type>::ArrayConstIterator(pointer ptr) { ptr_ = ptr; }

    template <class value_type>
    typename ArrayConstIterator<value_type>::reference ArrayConstIterator<value_type>::operator*()const { return *ptr_; }

    template <class value_type>
    typename ArrayConstIterator<value_type>::pointer ArrayConstIterator<value_type>::operator&() { return ptr_; }
    
    template <class value_type>
    ArrayConstIterator<value_type>& ArrayConstIterator<value_type>::operator+(int n) const {
        ptr_ = ptr_ + n;
        return *this;
    }
    
    template <class value_type>
    ArrayConstIterator<value_type>& ArrayConstIterator<value_type>::operator++() const {
        ++ptr_;
        return *this;
    }
    
    template <class value_type>
    ArrayConstIterator<value_type>& ArrayConstIterator<value_type>::operator--() const {
        --ptr_;
        return *this;
    }

    template <class value_type>
    bool ArrayConstIterator<value_type>::operator==(const ArrayConstIterator n) { return ptr_ == n.ptr_; }

    template <class value_type>
    bool ArrayConstIterator<value_type>::operator!=(const ArrayConstIterator n) { return ptr_ != n.ptr_; }

}