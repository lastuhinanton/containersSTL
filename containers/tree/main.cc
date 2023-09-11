#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "set/s21_set.h" 

int main() {
  std::set<int> std_set = {10, 10, 10, 11, 12, 10, 11};
  std::cout << "std set = ";
  for(auto x: std_set){
    std::cout << x << " ";
  } std::cout << std::endl;

  std::cout << "my set = ";
  s21::set my_set = {10, 10, 10, 11, 12, 10, 11};

  my_set.print();



  return 0;
}