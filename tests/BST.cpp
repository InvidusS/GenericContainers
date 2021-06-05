#include <gtest/gtest.h>
#include "../src/BST.h"

class BSTTest : public ::testing::Test {
protected:
    BST<int> treeOfInt {7,3,2,24,14,16};

    void SetUp() override {
        
    }

    void TearDown() override {

    }
};

TEST_F(BSTTest, searchTest){
    EXPECT_TRUE(treeOfInt.search(14));
    EXPECT_FALSE(treeOfInt.search(15));
}

TEST_F(BSTTest, getRootTest){
    EXPECT_EQ(7, treeOfInt.getRoot()->value);
}

TEST_F(BSTTest, getMinValueTest){
    EXPECT_EQ(2, treeOfInt.getMinValue(treeOfInt.getRoot())-> value);
}

TEST_F(BSTTest, getMaxvalueTest){
    EXPECT_EQ(24, treeOfInt.getMaxValue(treeOfInt.getRoot())-> value);
}

TEST_F(BSTTest, deleteNodeTest){
    EXPECT_FALSE(treeOfInt.deleteNode(23));
    EXPECT_TRUE(treeOfInt.deleteNode(24));
}
