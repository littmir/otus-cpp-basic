#include "array.h"

#include <gtest/gtest.h>

struct ArrayFixture : public testing::Test {
  Array<double> array;
};

TEST(Array, IsCreatedWithArg) {
  Array<int> array(5);

  ASSERT_EQ(array.get_size(), 1);
  ASSERT_EQ(array[0], 5);
}

TEST(Array, IsCreatedWithoutArg) {
  Array<int> array;

  ASSERT_EQ(array.get_size(), 0);
}

TEST_F(ArrayFixture, GetSizeEmpty) {
  ASSERT_EQ(array.get_size(), 0);
  array.push_back(5);
  ASSERT_EQ(array.get_size(), 1);
}

TEST_F(ArrayFixture, GetSizeNonEmpty) {
  array.push_back(5);
  array.push_back(6);
  ASSERT_EQ(array.get_size(), 2);
}

TEST_F(ArrayFixture, PushBackEmpty) {
  array.push_back(5);

  ASSERT_EQ(array.get_size(), 1);
  ASSERT_EQ(array[0], 5);
}

TEST_F(ArrayFixture, PushBackNonEmpty) {
  array.push_back(5);

  array.push_back(6);

  ASSERT_EQ(array.get_size(), 2);
  ASSERT_EQ(array[0], 5);
  ASSERT_EQ(array[1], 6);
}

TEST_F(ArrayFixture, InsertEmpty) {
  array.insert(5, 0);

  ASSERT_EQ(array.get_size(), 1);
  ASSERT_EQ(array[0], 5);
}

TEST_F(ArrayFixture, InsertFront) {
  array.push_back(5);
  array.push_back(6);

  array.insert(4, 0);

  ASSERT_EQ(array.get_size(), 3);
  ASSERT_EQ(array[0], 4);
  ASSERT_EQ(array[1], 5);
  ASSERT_EQ(array[2], 6);
}

TEST_F(ArrayFixture, InsertMiddle) {
  array.push_back(5);
  array.push_back(6);

  array.insert(5.5, 1);

  ASSERT_EQ(array.get_size(), 3);
  ASSERT_EQ(array[0], 5);
  ASSERT_EQ(array[1], 5.5);
  ASSERT_EQ(array[2], 6);
}

TEST_F(ArrayFixture, InsertBack) {
  array.push_back(5);
  array.push_back(6);

  array.insert(7, 2);

  ASSERT_EQ(array.get_size(), 3);
  ASSERT_EQ(array[0], 5);
  ASSERT_EQ(array[1], 6);
  ASSERT_EQ(array[2], 7);
}

TEST_F(ArrayFixture, EraseEmpty) {
  array.erase(0);

  ASSERT_EQ(array.get_size(), 0);
}

TEST_F(ArrayFixture, EraseFrontAndBack) {
  array.push_back(5);
  
  array.erase(1);

  ASSERT_EQ(array.get_size(), 0);
}

TEST_F(ArrayFixture, EraseFront) {
  array.push_back(5);
  array.push_back(6);
  
  array.erase(1);

  ASSERT_EQ(array.get_size(), 1);
  ASSERT_EQ(array[0], 6);
}

TEST_F(ArrayFixture, ErasMiddle) {
  array.push_back(5);
  array.push_back(6);
  array.push_back(7);
  
  array.erase(2);

  ASSERT_EQ(array.get_size(), 2);
  ASSERT_EQ(array[0], 5);
  ASSERT_EQ(array[1], 7);
}

TEST_F(ArrayFixture, ErasBack) {
  array.push_back(5);
  array.push_back(6);
  array.push_back(7);
  
  array.erase(3);

  ASSERT_EQ(array.get_size(), 2);
  ASSERT_EQ(array[0], 5);
  ASSERT_EQ(array[1], 6);
}

TEST_F(ArrayFixture, GetElement) {
  array.push_back(5);

  ASSERT_EQ(array[0], 5);
}
