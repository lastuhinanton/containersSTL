#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    s21::vector<int> C(A);
    std::cout << (A == C) << std::endl;
    return 0;
}