#ifndef S21_SET_H
#define S21_SET_H
// #include <iostream>
#include "../tree/avlTree.h"
namespace s21{
class set
{
private:
    s21::AVLTree<int> data_;
    int total;

public:
    set():total(0){data_.set_repeate_value(false);}
    set(std::initializer_list<int> values);
    ~set();
    void insert(int value);
    void erase(int value){data_.remove(value); total --;}
    void print(){data_.print();}
    void clear(){data_.clear();}


};  
}

#endif // S21_SET_H
