#include <cmath>
#include <gtest/gtest.h>

#include "Set/Set.hpp"

using namespace std;

class SetTest : public ::testing::Test {
protected:
  Set set;
};

TEST_F(SetTest, ContainsOnEmptys) { EXPECT_FALSE(set.contains(10)); }

TEST_F(SetTest, ContainsAfterSingleInsert) {
  set.insert(10);
  EXPECT_TRUE(set.contains(10));
  EXPECT_FALSE(set.contains(20));
}

TEST_F(SetTest, ContainsMultipleInserts) {
  set.insert(10);
  set.insert(20);
  set.insert(30);

  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
  EXPECT_TRUE(set.contains(30));
  EXPECT_FALSE(set.contains(40));
}

TEST_F(SetTest, ContainsWithDuplicateInsertions) {
  set.insert(10);
  set.insert(10);
  EXPECT_TRUE(set.contains(10));
  EXPECT_FALSE(set.contains(20));
}

TEST_F(SetTest, ContainsAfterRotationLL) {
  set.insert(10);
  set.insert(20);
  set.insert(30); // Causes an LL rotation
  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
  EXPECT_TRUE(set.contains(30));
}

TEST_F(SetTest, ContainsAfterRotationRR) {
  set.insert(30);
  set.insert(20);
  set.insert(10); // Causes an RR rotation
  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
  EXPECT_TRUE(set.contains(30));
}

TEST_F(SetTest, ContainsAfterRotationLR) {
  set.insert(30);
  set.insert(10);
  set.insert(20); // Causes an LR rotation
  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
  EXPECT_TRUE(set.contains(30));
}

TEST_F(SetTest, ContainsAfterRotationRL) {
  set.insert(10);
  set.insert(30);
  set.insert(20); // Causes an RL rotation
  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
  EXPECT_TRUE(set.contains(30));
}

TEST_F(SetTest, ContainsWithNegativeValues) {
  set.insert(-10);
  set.insert(-20);
  EXPECT_TRUE(set.contains(-10));
  EXPECT_TRUE(set.contains(-20));
  EXPECT_FALSE(set.contains(-30));
}

TEST_F(SetTest, Insertion) {
  set.insert(1);
  EXPECT_EQ(set.getRoot()->key, 1);
}

TEST_F(SetTest, TestGetBalance) {
  set.insert(1);
  ASSERT_EQ(set.getBalanceForTest(set.getRoot()), 0);
}

TEST_F(SetTest, InsertDuplicate) {
  set.insert(5);
  set.insert(5);
  EXPECT_EQ(set.size(), 1);
}

TEST_F(SetTest, Emptys) {
  EXPECT_EQ(set.size(), 0);
  EXPECT_EQ(set.getHeight(), 0);
  EXPECT_FALSE(set.contains(42));
}

TEST_F(SetTest, InsertSingleElement) {
  set.insert(10);
  EXPECT_EQ(set.size(), 1);
  set.contains(10);
  EXPECT_EQ(set.getHeight(), 1);
}

TEST_F(SetTest, HeightBoundAfterMultipleInsert) {
  const int n = 15;
  for (int i = 0; i < n; ++i) {
    set.insert(i);
  }
  int h = set.getHeight();
  int bound = static_cast<int>(floor(log2(n))) + 1;
  EXPECT_LE(h, bound);
}

TEST_F(SetTest, SwapEmptyTrees) {
  Set otherSet;
  set.swap(otherSet);
  EXPECT_TRUE(set.empty());
  EXPECT_TRUE(otherSet.empty());
}

TEST_F(SetTest, SwapWithEmptyTree) {
  Set otherSet;
  otherSet.insert(10);
  set.swap(otherSet);
  EXPECT_TRUE(set.contains(10));
  EXPECT_FALSE(otherSet.contains(10));
}

TEST_F(SetTest, SwapNonEmptyTrees) {
  set.insert(10);
  set.insert(20);
  set.insert(30);

  Set otherSet;
  otherSet.insert(40);
  otherSet.insert(50);
  set.swap(otherSet);
  EXPECT_TRUE(set.contains(40));
  EXPECT_TRUE(set.contains(50));
  EXPECT_FALSE(set.contains(10));
  EXPECT_FALSE(set.contains(20));
  EXPECT_FALSE(set.contains(30));
}

TEST_F(SetTest, SwapWithItself) {
  set.insert(10);
  set.insert(20);
  set.swap(set);
  EXPECT_TRUE(set.contains(10));
  EXPECT_TRUE(set.contains(20));
}

TEST_F(SetTest, AfterSwapOriginalEmpty) {
  Set otherSet;
  set.insert(100);
  set.swap(otherSet);
  EXPECT_TRUE(set.empty());
  EXPECT_FALSE(otherSet.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}