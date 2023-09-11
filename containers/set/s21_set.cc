#include "s21_set.h"
namespace s21{
void set::insert(int value){
    data_.insert(value); 
    total ++;
}
set::set(std::initializer_list<int> values){
    for (auto val: values) {data_.insert(val);}
}

set::~set() {
    // Perform cleanup, if necessary
}
}