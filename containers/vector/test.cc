#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    s21::vector<int> A1{7};
    std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> B1{7};
    std::vector<int> D;

    std::cout << B[1] << std::endl;
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

    // s21::vector<int> C{1, 2, 3, 4, 5, 6, 7};
    // std::cout << C.size() << " " << C.capacity() << std::endl;
    // C.reserve(10);
    // std::cout << C.size() << " " << C.capacity() << std::endl;
    // C.shrink_to_fit();
    // std::cout << C.size() << " " << C.capacity() << std::endl;
    // C.reserve(3);
    // std::cout << C.size() << " " << C.capacity() << std::endl;

    // auto C = B.front();
    // C = 20;
    // std::cout << B.front() << std::endl;
    // std::cout << A.back() << std::endl;
    // std::cout << B.back() << std::endl;

    // auto A1 = A.back();
    // auto B1 = B.back();

    // std::cout << A1 + 14 << std::endl;
    // std::cout << B1 + 14 << std::endl;

    // std::cout << *(A.data()) << std::endl;
    // *(A.data()) = 7;
    // std::cout << *(A.data()) << std::endl;
    // std::cout << (1 == 1) + 1 << std::endl;
    // std::cout << ++C << std::endl;
    // C = 7;
    // auto C1 = B.front();
    // std::cout << ++C1 << std::endl;
    // std::cout << ++C << std::endl;

    // std::cout << A.size() << A.capacity() << std::endl;
    // std::cout << A1.size() << A1.capacity() << std::endl;
    // A.swap(A1);
    // std::cout << A.size() << A.capacity() << std::endl;
    // std::cout << A1.size() << A1.capacity() << std::endl;
    // std::cout << B.size() << B.capacity() << std::endl;
    // std::cout << B1.size() << B1.capacity() << std::endl;
    // B.swap(B1);
    // std::cout << B.size() << B.capacity() << std::endl;
    // std::cout << B1.size() << B1.capacity() << std::endl;

    // std::cout << B.size() << std::endl;
    // B.erase(B.begin());
    // std::cout << B.size() << std::endl;
    return 0;
}