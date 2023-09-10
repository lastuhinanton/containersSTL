#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <cmath>
#include <limits>
#include <iostream>

namespace s21 {

template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

template <class T>
class vector {
  public:
    // Vector Member type
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = VectorIterator<value_type>;
    using const_iterator = VectorConstIterator<value_type>;
    using size_type = std::size_t;
    using pointer = value_type *;

    // Vector Member functions
    vector();
    vector(size_type n);
    vector(std::initializer_list<value_type> const &items);
    vector(const vector &v);
    // vector(vector &&v);
    ~vector();
    // vector operator=(vector &&v);

    // My own functions
    bool operator==(const vector &v);

    // Vector Capacity
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // void reserve(size_type size);
    // size_type capacity();
    // void shrink_to_fit();

    // Vector Element access
    reference at(size_type pos);
    reference operator[](size_type pos);
    // const_reference front();
    // const_reference back();
    // T* data();


    // Vector Iterators
    iterator begin();
    iterator end();

    // Vector Modifiers
    // void clear();
    // iterator insert(iterator pos, const_reference value);
    // void erase(iterator pos);
    // void push_back(const_reference value);
    // void pop_back();
    // void swap(vector& other);

  private:
    size_type size_;
    size_type capacity_;
    value_type *vector_;

    // My own functions
    void NullVector();
    void InitVector(size_type n);
    void DeleteVector();
    void CopyVector(const vector &v);


};

}

#include "s21_vector.tpp"
#include "VectorIterators.tpp"
#endif // S21_VECTOR_H
