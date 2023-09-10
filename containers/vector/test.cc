#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    auto itr = A.begin();
    auto itr1 = A.begin();
    itr1 = itr1 + 2;
    std::cout << *(itr) << std::endl;
    std::cout << *(++itr) << std::endl;
    std::cout << *(--itr) << std::endl;
    std::cout << *(itr + 4) << std::endl;
    std::cout << (A.begin() == A.begin()) << std::endl;
    std::cout << (itr == itr1) << std::endl;
    std::cout << (itr != itr1) << std::endl;
    std::cout << (A.end() == A.end()) << std::endl;

    std::cout << std::endl;

    std::vector<int> C{1, 2, 3, 4, 5, 6, 7};
    auto temp1 = C.front();
    auto temp2 = C.back();
    auto temp0 = C.begin();
    auto temp01 = C.begin();
    temp01 = temp01 + 2;
    std::cout << *temp0 << std::endl;
    std::cout << *(++temp0) << std::endl;
    std::cout << *(--temp0) << std::endl;
    std::cout << *(temp0 + 4) << std::endl;
    std::cout << (C.begin() == C.begin()) << std::endl;
    std::cout << (temp0 == temp01) << std::endl;
    std::cout << (temp0 != temp01) << std::endl;
    std::cout << (C.end() == C.end()) << std::endl;
    return 0;
}