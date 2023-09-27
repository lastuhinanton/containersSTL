#include <gtest/gtest.h>
#include "s21_vector.h"

TEST(S21VectorTest, DefaultConstructor) {
  s21::vector<int> A;
  std::vector<int> B;
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, SizeConstructor) {
  s21::vector<int> A(21);
  std::vector<int> B(21);
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
}

TEST(S21VectorTest, LightArrayConstructor) {
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

TEST(S21VectorTest, CopyConstructor) {
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

TEST(S21VectorTest, MoveConstructor) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A_test(std::move(A));

  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B_test(std::move(B));
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A_test.size(), B_test.size());
  ASSERT_EQ(A_test.capacity(), B_test.capacity());
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

TEST(S21VectorTest, FrontBackData) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(A.front(), B.front());
  ASSERT_EQ(A.back(), B.back());
  ASSERT_EQ(*A.data(), *B.data());
}

TEST(S21VectorTest, PushPopBack) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  ASSERT_EQ(A.back(), B.back());
  A.pop_back();
  B.pop_back();
  ASSERT_EQ(A.back(), B.back());
  A.push_back(21);
  B.push_back(21);
  ASSERT_EQ(A.back(), B.back());
}

TEST(S21VectorTest, ClearContents) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.clear();
  A1.clear();
  B.clear();
  B1.clear();
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, EraseContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.erase(A.begin());
  A1.erase(A1.begin());
  B.erase(B.begin());
  B1.erase(B1.begin());
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A1.capacity(), B1.capacity());

  A.push_back(21);
  A1.push_back(21);
  B.push_back(21);
  B1.push_back(21);

  A.erase(--A.end());
  A1.erase(--A1.end());
  B.erase(--B.end());
  B1.erase(--B1.end());
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A.capacity(), B.capacity());
  ASSERT_EQ(A1.size(), B1.size());
  ASSERT_EQ(A1.capacity(), B1.capacity());
}

TEST(S21VectorTest, InsertContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  A.insert(A.begin(), 21);
  A1.insert(A1.begin(), 21);
  B.insert(B.begin(), 21);
  B1.insert(B1.begin(), 21);
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());

  A.push_back(21);
  A1.push_back(21);
  B.push_back(21);
  B1.push_back(21);

  A.insert(A.end(), 21);
  A1.insert(A1.end(), 21);
  B.insert(B.end(), 21);
  B1.insert(B1.end(), 21);
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, SwapContent) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> A1{1};
  std::vector<int> B1{1};

  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());

  A.swap(A1);
  std::swap(B, B1);
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
  
  A.swap(A1);
  std::swap(B, B1);
  
  ASSERT_EQ(A.size(), B.size());
  ASSERT_EQ(A1.size(), B1.size());
}

TEST(S21VectorTest, VectorIterator) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};

  auto A_iterator = A.begin();
  auto A1_iterator = A.begin();
  auto B_iterator = B.begin();
  A_iterator = A_iterator + 2;
  B_iterator = B_iterator + 2;

  ASSERT_EQ(*A_iterator, *B_iterator);
  ASSERT_EQ(&A_iterator, &A_iterator);
  ASSERT_TRUE(A_iterator == A_iterator);
  ASSERT_TRUE(A_iterator != A1_iterator);
}

TEST(S21VectorTest, VectorConstIterator) {
  s21::vector<int> A{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> B{1, 2, 3, 4, 5, 6, 7};

  auto A_iterator = A.cbegin();
  auto A1_iterator = A.cbegin();
  auto B_iterator = B.cbegin();

  A_iterator = A_iterator + 2;
  B_iterator = B_iterator + 2;

  ASSERT_EQ(*A_iterator, *B_iterator);
  ASSERT_EQ(&A_iterator, &A_iterator);
  ASSERT_TRUE(A_iterator == A_iterator);
  ASSERT_TRUE(A_iterator != A1_iterator);
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
