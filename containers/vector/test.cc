#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    s21::vector<int> B{1, 2, 3, 4, 5, 6, 7};
    // std::cout << A.size() << "(A)" << std::endl;
    // std::cout << B.size() << "(B)" << std::endl;
    // s21::vector<int> C;
    // std::cout << C.size() << "(C)"  << std::endl;
    // C = std::move(B);
    // std::cout << A.size() << "(A)" << std::endl;
    // std::cout << B.size() << "(B)" << std::endl;
    // std::cout << C.size() << "(C)" << std::endl;
    // // auto itr = A.begin();
    // std::cout << A.size() << "(A)" << std::endl;
    // std::cout << B.size() << "(B)" << std::endl;
    // std::cout << C.size() << "(C)" << std::endl;
    // // itr + 2;
    // // std::cout << *itr << std::endl;
    // std::cout << (A == C) << std::endl;
    // std::cout << A.size() << std::endl;
    // std::cout << B.size() << std::endl;
    // std::cout << A.capacity() << std::endl;
    // std::cout << B.capacity() << std::endl;

    std::vector<int> C{1, 2, 3, 4, 5, 6, 7};
    std::cout << C.size() << " " << C.capacity() << std::endl;
    C.reserve(10);
    std::cout << C.size() << " " << C.capacity() << std::endl;
    C.shrink_to_fit();
    std::cout << C.size() << " " << C.capacity() << std::endl;
    C.reserve(3);
    std::cout << C.size() << " " << C.capacity() << std::endl;
    return 0;
}