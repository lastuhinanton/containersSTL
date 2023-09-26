#include <gtest/gtest.h>
#include "s21_array.h"

TEST(S21MatrixTest, DefaultConstructor) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A12{1, 2, 3, 4, 21, 6, 7};
  s21::array<int, 7> A13{1, 2, 3, 4, 21, 6, 7};
  s21::array<int, 1> A1{7};
  s21::array<int, 7> A2(A12);
  s21::array<int, 7> A3;
  s21::array<int, 0> A4;
  s21::array<int, 7> A5(std::move(A13));

  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B12{1, 2, 3, 4, 21, 6, 7};
  std::array<int, 7> B13{1, 2, 3, 4, 21, 6, 7};
  std::array<int, 1> B1{7};
  std::array<int, 7> B2(B12);
  std::array<int, 7> B3;
  std::array<int, 0> B4;
  std::array<int, 7> B5(std::move(B13));

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A12.size(), B12.size());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A2.size(), B2.size());
  ASSERT_EQ(A3.size(), B3.size());
  ASSERT_EQ(A4.size(), B4.size());
  ASSERT_EQ(A5.size(), B5.size());
}

TEST(S21MatrixTest, Empty) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.empty(), B.empty());
  ASSERT_EQ(A1.empty(), B1.empty());
}

TEST(S21MatrixTest, Size) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21MatrixTest, MaxSize) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 0> A1;
  std::array<int, 0> B1;
  ASSERT_EQ(A.max_size(), B.max_size());
  ASSERT_EQ(A1.max_size(), B1.max_size());
}

TEST(S21MatrixTest, At) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.at(0), B.at(0));
  ASSERT_EQ(A.at(1), B.at(1));
  ASSERT_EQ(A.at(2), B.at(2));
  ASSERT_EQ(A.at(3), B.at(3));
  ASSERT_EQ(A.at(4), B.at(4));
  ASSERT_EQ(A.at(5), B.at(5));
  ASSERT_EQ(A.at(6), B.at(6));
}

TEST(S21MatrixTest, Square) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A[0], B[0]);
  ASSERT_EQ(A[1], B[1]);
  ASSERT_EQ(A[2], B[2]);
  ASSERT_EQ(A[3], B[3]);
  ASSERT_EQ(A[4], B[4]);
  ASSERT_EQ(A[5], B[5]);
  ASSERT_EQ(A[6], B[6]);
}

TEST(S21MatrixTest, FrontBack) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.front(), B.front());
  ASSERT_EQ(A.front(), B.front());
}

TEST(S21MatrixTest, Data) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  ASSERT_EQ(A.data()[5], B.data()[5]);
  ASSERT_EQ(*A.data(), *B.data());
}

TEST(S21MatrixTest, Fill) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  A.fill(7);
  A1.fill(7);
  EXPECT_TRUE(A == A1);
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B.size());
}

TEST(S21MatrixTest, IteratorOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};

  auto A_b = A.begin();
  auto B_b = B.begin();

  EXPECT_TRUE(*A_b == *B_b);
  ++A_b;
  ++B_b;
  EXPECT_TRUE(*A_b == *B_b);
  --A_b;
  --B_b;
  EXPECT_TRUE(*A_b == *B_b);

  auto A_e = A.end();
  auto B_e = B.end();

  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);

  ASSERT_EQ(&A_e, &A_e);

  A_e = A_e + 1;
  B_e = B_e + 1;
  EXPECT_TRUE(*A_e == *B_e);

  EXPECT_TRUE(*A_e != *A_b);
}

TEST(S21MatrixTest, constIteratorOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};

  auto A_b = A.cbegin();
  auto B_b = B.cbegin();

  EXPECT_TRUE(*A_b == *B_b);
  ++A_b;
  ++B_b;
  EXPECT_TRUE(*A_b == *B_b);
  --A_b;
  --B_b;
  EXPECT_TRUE(*A_b == *B_b);

  auto A_e = A.cend();
  auto B_e = B.cend();

  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);
  --A_e;
  --B_e;
  EXPECT_TRUE(*A_e == *B_e);

  ASSERT_EQ(&A_e, &A_e);

  A_e = A_e + 1;
  B_e = B_e + 1;
  EXPECT_TRUE(*A_e == *B_e);

  EXPECT_TRUE(*A_e != *A_b);
}

TEST(S21MatrixTest, overloadOperators) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A2{111, 2, 3, 21, 5, 7, 7};

  EXPECT_TRUE(A == A1);
  EXPECT_FALSE(A == A2);
}

TEST(S21MatrixTest, arrayModifiers) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A1{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A2{111, 2, 3, 21, 5, 7, 7};
  s21::array<int, 7> A3{111, 2, 3, 21, 5, 7, 7};

  EXPECT_TRUE(A == A1);
  A1.swap(A2);
  EXPECT_FALSE(A == A1);
  EXPECT_TRUE(A1 == A3);
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
