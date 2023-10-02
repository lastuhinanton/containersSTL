#include "s21_vector.h"
#include <vector>

int main(void) {
    s21::vector<int> v = {1, 2, 3, 4, 5};
    // for (auto i = v.begin(); i != v.end(); ++i) {
    //     std::cout << *i;
    // }
    // std::cout << std::endl;
    // auto start = v.begin() + 2;
    // std::cout << *start << std::endl;
    // v.insert(start, 7);
    // for (auto i = v.begin(); i != v.end(); ++i) {
    //     std::cout << *i;
    // }
    // std::cout << std::endl << *start;
    // std::cout << *(v.cbegin() + 4) << std::endl;

    // std::cout << v.size() << v.capacity() << std::endl;
    v.insert_many(v.cbegin(), 1, 2, 3, 4, 5, 6, 7);
    std::cout <<std::endl;
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << *i;
    }

    // s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
    // s21::vector<int> A1{9};
    // std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
    // std::vector<int> B1{9};


    // std::cout << A.back() << " " << A1.back() << std::endl;
    // A.pop_back();
    // A1.pop_back();
    // std::cout << A.back() << " " << A1.back() << std::endl;

    // std::cout << A1.size() << A1.capacity() << std::endl;
    // for (auto t = A1.begin(); t != A1.end(); ++t) {
    //     std::cout << *t << " ";
    // }
    // std::cout << std::endl;
    // A1.erase(--A1.end());
    // for (auto t = A1.begin(); t != A1.end(); ++t) {
    //     std::cout << *t << " ";
    // }
    // std::cout << std::endl;
    // std::cout << A1.size() << A1.capacity() << std::endl;

    // std::cout << B1.size() << std::endl;
    // B1.pop_back();
    // std::cout << B1.size() << std::endl;

    // std::cout << A.capacity() << A.size() << " " << A1.capacity() << A1.size() << std::endl;
    // A1.reserve(21);
    // std::cout << A.capacity() << A.size() << " " << A1.capacity() << A1.size() << std::endl;
    // std::cout << A1.back() << std::endl;
    // A.swap(A1);
    // std::cout << A.capacity() << A.size() << " " << A1.capacity() << A1.size()  << std::endl;
    // std::cout << A1.back() << std::endl;

    // std::cout << B1.back() << std::endl;
    // std::cout << B1.size() << " " << B1.capacity() << std::endl;
    // B1.pop_back();
    // std::cout << B1.back() << std::endl;
    // std::cout << B1.size() << " " << B1.capacity() << std::endl;

    // std::cout << A.size() << " " << A1.size() << std::endl;
    // std::cout << B.size() << " " << B1.size() << std::endl;

    // A1 = std::move(A);
    // B1 = B;
    // std::cout << A.size() << " " << A1.size() << std::endl;
    // std::cout << B.size() << " " << B1.size() << std::endl;
    // std::cout << B.capacity() << " " << B1.capacity() << std::endl;

    // A2 = A;

    // auto i = A.begin();
    // auto i1 = A.cbegin();
    // auto i2 = A.cbegin();
    // auto b1 = B.begin();
    // auto b2 = B.begin();
    
    // *i1 = 21;
    // *b1 = 21;
    // // std::cout << *(i1 + 1) << std::endl;
    // // std::cout << *(--i1) << std::endl;
    // std::cout << (i1 == i2) << std::endl;
    // std::cout << (b1 == b2) << std::endl;
    // std::cout << typeid(i).name() << std::endl;
    // std::cout << *(A.begin()) << " " << &(A.begin() + 1) << " " << &(A.begin() + 2) << std::endl;




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