#include <gtest/gtest.h>
#include "../src/forward_list.h"

class ListTest : public ::testing::Test {
protected:
    List<int> listOfInt1 {7,2,9,3,1};
    List<int> listOfInt2 {1,3,9,2,7};
    List<int> listOfInt3;
    List<char> listOfChar {'a', 'b', 'c', 'd', 'e'};
    List<char> listOfChar2 {'a', 'b', 'c', 'd'};
    List<const char*> listOfString {"aaa", "bbb", "ccc"};
    List<const char*> listOfString2 {"bbb", "ccc"};

    void SetUp() override {
        listOfInt2.reverse();
    }

    void TearDown() override {

    }
};

TEST_F(ListTest, frontTest){
    EXPECT_EQ(1, listOfInt1.frontOfList());
    EXPECT_EQ(1, listOfInt2.frontOfList());
    EXPECT_EQ('e', listOfChar.frontOfList());
}

TEST_F(ListTest, isEmptyTest){
    EXPECT_FALSE(listOfInt1.isEmpty());
    EXPECT_TRUE(listOfInt3.isEmpty());
}

TEST_F(ListTest, reverseTest){
    EXPECT_TRUE(listOfInt1 == listOfInt2);
    listOfInt1.reverse();
    EXPECT_FALSE(listOfInt1 == listOfInt2);
}

TEST_F(ListTest, equalityOperatorTest){
    EXPECT_FALSE(listOfInt3 == listOfInt2);
    EXPECT_TRUE(listOfInt1 == listOfInt2);
}

TEST_F(ListTest, ereaseTest){
    EXPECT_FALSE(listOfString == listOfString2);
    listOfString.ereaseElement("aaa");
    EXPECT_TRUE(listOfString == listOfString2);
}

TEST_F(ListTest, searchTest){
    EXPECT_TRUE(listOfChar.search('b'));
    EXPECT_FALSE(listOfChar.search('z'));
    EXPECT_TRUE(listOfString.search("aaa"));
    EXPECT_FALSE(listOfString.search("zzz"));
    EXPECT_TRUE(listOfInt1.search(3));
    EXPECT_FALSE(listOfInt1.search(4));
}

TEST_F(ListTest, popFrontTest){
    EXPECT_FALSE(listOfChar == listOfChar2);
    listOfChar.popFront();
    EXPECT_TRUE(listOfChar == listOfChar2);
}
