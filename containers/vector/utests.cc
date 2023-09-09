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

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
