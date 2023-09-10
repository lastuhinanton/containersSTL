#include <gtest/gtest.h>
#include "s21_vector.h"

TEST(S21MatrixTest, DefaultConstructor) {
  s21::vector<int> A;
  std::vector<int> B;
  ASSERT_EQ(A.size(), B.size());
}

TEST(S21MatrixTest, SizeConstructor) {
  s21::vector<int> A(21);
  std::vector<int> B(21);
  ASSERT_EQ(A.size(), B.size());
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
}

TEST(S21MatrixTest, DeleteConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.at(0), B.at(0));
  ASSERT_EQ(A.at(1), B.at(1));
  ASSERT_EQ(A.at(2), B.at(2));
  ASSERT_EQ(A.at(3), B.at(3));
  ASSERT_EQ(A.at(4), B.at(4));
  ASSERT_EQ(A.at(5), B.at(5));
  ASSERT_EQ(A.at(6), B.at(6));
}

TEST(S21MatrixTest, OperatorAccess) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A[0], B[0]);
  ASSERT_EQ(A[1], B[1]);
  ASSERT_EQ(A[2], B[2]);
  ASSERT_EQ(A[3], B[3]);
  ASSERT_EQ(A[4], B[4]);
  ASSERT_EQ(A[5], B[5]);
  ASSERT_EQ(A[6], B[6]);
}

TEST(S21MatrixTest, MaxSize) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.max_size(), B.max_size());
}

TEST(S21MatrixTest, Empty) {
  s21::vector<int> A;
  s21::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(A.empty());
  EXPECT_FALSE(B.empty());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
