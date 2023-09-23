#include <gtest/gtest.h>
#include "s21_vector.h"

TEST(S21MatrixTest, DefaultConstructor) {
  s21::vector<int> A;
  std::vector<int> B;
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21MatrixTest, SizeConstructor) {
  s21::vector<int> A(21);
  std::vector<int> B(21);
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21MatrixTest, LightArrayConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.at(0), B.at(0));
  ASSERT_EQ(A.at(1), B.at(1));
  ASSERT_EQ(A.at(2), B.at(2));
  ASSERT_EQ(A.at(3), B.at(3));
  ASSERT_EQ(A.at(4), B.at(4));
  ASSERT_EQ(A.at(5), B.at(5));
  ASSERT_EQ(A.at(6), B.at(6));
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21MatrixTest, CopyConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A_test(A);
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B_test(B);
  ASSERT_EQ(A.size(), A_test.size());
  ASSERT_EQ(B.size(), B_test.size());
  ASSERT_EQ(A.capacity(), A_test.capacity());
  ASSERT_EQ(B.capacity(), B_test.capacity());
  EXPECT_TRUE(A == A_test);
  EXPECT_TRUE(B == B_test);
}

TEST(S21MatrixTest, MoveConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A_test(std::move(A));

  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B_test(std::move(B));
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, Empty) {
  s21::vector<int> A;
  std::vector<int> B;
  EXPECT_TRUE(A.empty() == B.empty());

  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A1.empty() == B1.empty());
}

TEST(S21VectorTest, Size) {
  s21::vector<int> A;
  std::vector<int> B;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());
}

TEST(S21VectorTest, MaxSize) {
  s21::vector<int> A;
  std::vector<int> B;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A.max_size() == B.max_size());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
}

TEST(S21VectorTest, AssignOperator) {
  s21::vector<int> A;
  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A2;
  std::vector<int> B;
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B2;

  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());
  
  A = A1;
  B = B1;
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());

  A = A2;
  A1 = A2;
  B = B2;
  B1 = B2;
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A1.size() == B1.size());
}

TEST(S21VectorTest, ReserveCapacityShrink) {
  s21::vector<int> A;
  std::vector<int> B;
  A.reserve(21);
  B.reserve(21);
  EXPECT_EQ(A.size(), B.size());
  EXPECT_EQ(A.capacity(), B.capacity());
  EXPECT_EQ(A.max_size(), B.max_size());
  A.shrink_to_fit();
  B.shrink_to_fit();
  EXPECT_TRUE(A.size() == B.size());
  EXPECT_TRUE(A.capacity() == B.capacity());
  EXPECT_TRUE(A.max_size() == B.max_size());

  s21::vector<int> A1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B1{1, 2, 3, 4, 5, 6, 7};
  A1.reserve(21);
  B1.reserve(21);
  EXPECT_TRUE(A1.size() == B1.size());
  EXPECT_TRUE(A1.capacity() == B1.capacity());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
  A1.shrink_to_fit();
  B1.shrink_to_fit();
  EXPECT_TRUE(A1.size() == B1.size());
  EXPECT_TRUE(A1.capacity() == B1.capacity());
  EXPECT_TRUE(A1.max_size() == B1.max_size());
}

TEST(S21MatrixTest, FrontBackData) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.front(), B.front());
  ASSERT_EQ(A.back(), B.back());
  ASSERT_EQ(*A.data(), *B.data());
}

TEST(S21MatrixTest, PushPopBack) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.back(), B.back());
  A.pop_back();
  B.pop_back();
  // ASSERT_EQ(A.back(), B.back());
  // A.push_back(21);
  // B.push_back(21);
  // ASSERT_EQ(A.back(), B.back());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
