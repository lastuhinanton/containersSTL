#include "s21_array.h"
#include <array>

int main(void) {
    s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
    s21::array<int, 7> A12{1, 2, 3, 4, 21, 6, 7};
    s21::array<int, 1> A1{7};
    s21::array<int, 0> A2;

    std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
    std::array<int, 7> B12{1, 2, 3, 4, 21, 6, 7};
    std::array<int, 1> B1{7};
    std::array<int, 0> B2;
    
    // std::cout << (A.size() == B.size()) << std::endl;
    // std::cout << (A1.size() == B1.size()) << std::endl;
    // std::cout << (A2.size() == B2.size()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (A.empty() == B.empty()) << std::endl;
    // std::cout << (A1.empty() == B1.empty()) << std::endl;
    // std::cout << (A2.empty() == B2.empty()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (A.max_size() == B.max_size()) << std::endl;
    // std::cout << (A1.max_size() == B1.max_size()) << std::endl;
    // std::cout << (A2.max_size() == B2.max_size()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (A[0] == B[0]) << std::endl;
    // std::cout << (A1[0] == B1[0]) << std::endl;
    // // std::cout << (A2[0] == B2[0]) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (A.front() == B.front()) << std::endl;
    // std::cout << (A1.front() == B1.front()) << std::endl;
    // // std::cout << (A2.front() == B2.front()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (A.back() == B.back()) << std::endl;
    // std::cout << (A1.back() == B1.back()) << std::endl;
    // // std::cout << (A2.back() == B2.back()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (*A.data() == *B.data()) << std::endl;
    // std::cout << (*A1.data() == *B1.data()) << std::endl;
    // // std::cout << (A2.data() == B2.data()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (*A.begin() == *B.begin()) << std::endl;
    // std::cout << (*A1.begin() == *B1.begin()) << std::endl;
    // // std::cout << (*A2.begin() == *B2.begin()) << std::endl;
    // std::cout << "===" << std::endl;
    // // std::cout << (*A.end() == *B.end()) << std::endl;
    // // std::cout << (*A1.end() == *B1.end()) << std::endl;
    // // std::cout << (*A2.begin() == *B2.begin()) << std::endl;
    // std::cout << "===" << std::endl;
    // std::cout << (*A.cbegin() == *B.cbegin()) << std::endl;
    // std::cout << (*A1.cbegin() == *B1.cbegin()) << std::endl;
    // // std::cout << (*A2.cbegin() == *B2.cbegin()) << std::endl;
    // std::cout << "===" << std::endl;
    // A = A12;
    // std::cout << &B << std::endl;
    // std::cout << &B12 << std::endl;
    // B = B12;
    // std::cout << &B << std::endl;
    // std::cout << &B12 << std::endl;
    // std::cout << (A.size() == B.size()) << std::endl;
    std::cout << "===" << std::endl;
    std::cout << "===" << std::endl;
    std::cout << "===" << std::endl;
    std::cout << "===" << std::endl;


    return 0;
}