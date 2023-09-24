#include <gtest/gtest.h>
#include "s21_array.h"

TEST(S21MatrixTest, DefaultConstructor) {
  s21::array<int, 7> A{111, 2, 3, 21, 5, 6, 7};
  s21::array<int, 7> A12{1, 2, 3, 4, 21, 6, 7};
  s21::array<int, 1> A1{7};
  s21::array<int, 0> A2;

  std::array<int, 7> B{111, 2, 3, 21, 5, 6, 7};
  std::array<int, 7> B12{1, 2, 3, 4, 21, 6, 7};
  std::array<int, 1> B1{7};
  std::array<int, 0> B2;


  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A12.size(), B12.size());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A2.size(), B2.size());
}

// TEST(S21MatrixTest, SizeConstructor) {
//   s21::vector<int> A(21);
//   std::vector<int> B(21);
//   ASSERT_EQ(A.size(), B.size());
// }

// TEST(S21MatrixTest, LightArrayConstructor) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   ASSERT_EQ(A.at(0), B.at(0));
//   ASSERT_EQ(A.at(1), B.at(1));
//   ASSERT_EQ(A.at(2), B.at(2));
//   ASSERT_EQ(A.at(3), B.at(3));
//   ASSERT_EQ(A.at(4), B.at(4));
//   ASSERT_EQ(A.at(5), B.at(5));
//   ASSERT_EQ(A.at(6), B.at(6));
// }

// TEST(S21MatrixTest, CopyConstructor) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   s21::vector<int> B(A);
//   EXPECT_TRUE(A == B);
//   std::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1(A);
//   EXPECT_TRUE(A1 == B1);
// }

// TEST(S21MatrixTest, MoveConstructor) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   s21::vector<int> A1(std::move(A));
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1(std::move(B));
//   EXPECT_TRUE(A.size() == B.size());
//   EXPECT_TRUE(A.capacity() == B.capacity());
//   EXPECT_TRUE(A == B);
//   EXPECT_TRUE(A1.size() == B1.size());
//   EXPECT_TRUE(A1.capacity() == B1.capacity());
//   EXPECT_TRUE(A1 == B1);
// }

// TEST(S21VectorTest, Empty) {
//   s21::vector<int> A;
//   std::vector<int> B;
//   EXPECT_TRUE(A == B);
//   EXPECT_TRUE(A.empty() == B.empty());
//   s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
//   EXPECT_TRUE(A1 == B1);
//   EXPECT_TRUE(A1.empty() == B1.empty());
// }

// TEST(S21VectorTest, Size) {
//   s21::vector<int> A;
//   std::vector<int> B;
//   s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
//   EXPECT_TRUE(A.size() == B.size());
//   EXPECT_TRUE(A1.size() == B1.size());
// }

// TEST(S21VectorTest, MaxSize) {
//   s21::vector<int> A;
//   std::vector<int> B;
//   s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
//   EXPECT_TRUE(A.max_size() == B.max_size());
//   EXPECT_TRUE(A1.max_size() == B1.max_size());
// }

// TEST(S21VectorTest, ReserveCapacityShrink) {
//   s21::vector<int> A;
//   std::vector<int> B;
//   A.reserve(21);
//   B.reserve(21);
//   s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
//   A1.reserve(21);
//   B1.reserve(21);
//   EXPECT_TRUE(A.size() == B.size());
//   EXPECT_TRUE(A.capacity() == B.capacity());
//   EXPECT_TRUE(A.max_size() == B.max_size());
//   EXPECT_TRUE(A1.size() == B1.size());
//   EXPECT_TRUE(A1.capacity() == B1.capacity());
//   EXPECT_TRUE(A1.max_size() == B1.max_size());
//   A.shrink_to_fit();
//   B.shrink_to_fit();
//   A1.shrink_to_fit();
//   B1.shrink_to_fit();
//   EXPECT_TRUE(A.size() == B.size());
//   EXPECT_TRUE(A.capacity() == B.capacity());
//   EXPECT_TRUE(A.max_size() == B.max_size());
//   EXPECT_TRUE(A1.size() == B1.size());
//   EXPECT_TRUE(A1.capacity() == B1.capacity());
//   EXPECT_TRUE(A1.max_size() == B1.max_size());
// }

// TEST(S21MatrixTest, DeleteAcess) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   ASSERT_EQ(A.at(0), B.at(0));
//   ASSERT_EQ(A.at(1), B.at(1));
//   ASSERT_EQ(A.at(2), B.at(2));
//   ASSERT_EQ(A.at(3), B.at(3));
//   ASSERT_EQ(A.at(4), B.at(4));
//   ASSERT_EQ(A.at(5), B.at(5));
//   ASSERT_EQ(A.at(6), B.at(6));
//   ASSERT_EQ(A[0], B[0]);
//   ASSERT_EQ(A[1], B[1]);
//   ASSERT_EQ(A[2], B[2]);
//   ASSERT_EQ(A[3], B[3]);
//   ASSERT_EQ(A[4], B[4]);
//   ASSERT_EQ(A[5], B[5]);
//   ASSERT_EQ(A[6], B[6]);
// }

// TEST(S21MatrixTest, FrontBackData) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   ASSERT_EQ(A.front(), B.front());
//   ASSERT_EQ(A.back(), B.back());
//   ASSERT_EQ(*A.data(), *B.data());
// }

// TEST(S21MatrixTest, FrontBackData) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   ASSERT_EQ(A.front(), B.front());
//   ASSERT_EQ(A.back(), B.back());
//   ASSERT_EQ(*A.data(), *B.data());
// }

// TEST(S21MatrixTest, PushPopBack) {
//   s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
//   std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
//   ASSERT_EQ(A.back(), B.back());
//   A.pop_back();
//   B.pop_back();
//   ASSERT_EQ(A.back(), B.back());
//   A.push_back(21);
//   B.push_back(21);
//   ASSERT_EQ(A.back(), B.back());
// }

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
