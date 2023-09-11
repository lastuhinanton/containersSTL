#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    s21::vector<int> B{1, 2, 3, 4, 5, 6, 7};
    std::cout << A.size() << "(A)" << std::endl;
    std::cout << B.size() << "(B)" << std::endl;
    s21::vector<int> C;
    std::cout << C.size() << "(C)"  << std::endl;
    C = std::move(B);
    std::cout << A.size() << "(A)" << std::endl;
    std::cout << B.size() << "(B)" << std::endl;
    std::cout << C.size() << "(C)" << std::endl;
    // auto itr = A.begin();
    // itr + 2;
    // std::cout << *itr << std::endl;
    std::cout << (A == C) << std::endl;
    std::cout << A.size() << std::endl;
    return 0;
}