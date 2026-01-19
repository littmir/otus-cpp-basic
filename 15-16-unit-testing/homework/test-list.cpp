#include "list.h"

#include <gtest/gtest.h>

struct ListFixture : public testing::Test {
  List<double> list;
};

TEST(List, IsCreatedWithArg) {
  List<int> list(5);

  ASSERT_EQ(list.get_size(), 1);
  ASSERT_EQ(list[0], 5);
}

TEST(List, IsCreatedWithoutArg) {
  List<int> list;

  ASSERT_EQ(list.get_size(), 0);
}

TEST_F(ListFixture, GetSizeEmpty) {
  ASSERT_EQ(list.get_size(), 0);
  list.push_back(5);
  ASSERT_EQ(list.get_size(), 1);
}

TEST_F(ListFixture, GetSizeNonEmpty) {
  list.push_back(5);
  list.push_back(6);
  ASSERT_EQ(list.get_size(), 2);
}

TEST_F(ListFixture, PushBackEmpty) {
  list.push_back(5);

  ASSERT_EQ(list.get_size(), 1);
  ASSERT_EQ(list[0], 5);
}

TEST_F(ListFixture, PushBackNonEmpty) {
  list.push_back(5);

  list.push_back(6);

  ASSERT_EQ(list.get_size(), 2);
  ASSERT_EQ(list[0], 5);
  ASSERT_EQ(list[1], 6);
}

TEST_F(ListFixture, InsertEmpty) {
  list.insert(5, 0);

  ASSERT_EQ(list.get_size(), 1);
  ASSERT_EQ(list[0], 5);
}

TEST_F(ListFixture, InsertFront) {
  list.push_back(5);
  list.push_back(6);

  list.insert(4, 0);

  ASSERT_EQ(list.get_size(), 3);
  ASSERT_EQ(list[0], 4);
  ASSERT_EQ(list[1], 5);
  ASSERT_EQ(list[2], 6);
}

TEST_F(ListFixture, InsertMiddle) {
  list.push_back(5);
  list.push_back(6);

  list.insert(5.5, 1);

  ASSERT_EQ(list.get_size(), 3);
  ASSERT_EQ(list[0], 5);
  ASSERT_EQ(list[1], 5.5);
  ASSERT_EQ(list[2], 6);
}

TEST_F(ListFixture, InsertBack) {
  list.push_back(5);
  list.push_back(6);

  list.insert(7, 2);

  ASSERT_EQ(list.get_size(), 3);
  ASSERT_EQ(list[0], 5);
  ASSERT_EQ(list[1], 6);
  ASSERT_EQ(list[2], 7);
}

TEST_F(ListFixture, EraseEmpty) {
  list.erase(0);

  ASSERT_EQ(list.get_size(), 0);
}

TEST_F(ListFixture, EraseFrontAndBack) {
  list.push_back(5);
  
  list.erase(1);

  ASSERT_EQ(list.get_size(), 0);
}

TEST_F(ListFixture, EraseFront) {
  list.push_back(5);
  list.push_back(6);
  
  list.erase(1);

  ASSERT_EQ(list.get_size(), 1);
  ASSERT_EQ(list[0], 6);
}

TEST_F(ListFixture, ErasMiddle) {
  list.push_back(5);
  list.push_back(6);
  list.push_back(7);
  
  list.erase(2);

  ASSERT_EQ(list.get_size(), 2);
  ASSERT_EQ(list[0], 5);
  ASSERT_EQ(list[1], 7);
}

TEST_F(ListFixture, ErasBack) {
  list.push_back(5);
  list.push_back(6);
  list.push_back(7);
  
  list.erase(3);

  ASSERT_EQ(list.get_size(), 2);
  ASSERT_EQ(list[0], 5);
  ASSERT_EQ(list[1], 6);
}

TEST_F(ListFixture, GetElement) {
  list.push_back(5);

  ASSERT_EQ(list[0], 5);
}
