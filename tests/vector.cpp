#include <gtest/gtest.h>
#include "../src/vector.h"

class VectorTest : public ::testing::Test{
protected:
    Vector<int> vectorOfInt {1,2,3,4,5};
    Vector<int> vectorOfInt2 {10,20,30};
    Vector<int> vectorOfInt3;

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(VectorTest, bracketOperatorTest){
    EXPECT_EQ(3, vectorOfInt[2]);
}

TEST_F(VectorTest, frontElementTest){
    EXPECT_EQ(1, vectorOfInt.frontElement());
    EXPECT_EQ(10, vectorOfInt2.frontElement());
}

TEST_F(VectorTest, backElementTest){
    EXPECT_EQ(5, vectorOfInt.backElement());
    EXPECT_EQ(30, vectorOfInt2.backElement());
}

TEST_F(VectorTest, isEmptyTest){
    EXPECT_FALSE(vectorOfInt.isEmpty());
    EXPECT_TRUE(vectorOfInt3.isEmpty());
}

TEST_F(VectorTest, sizeOfVectorTest){
    EXPECT_EQ(5, vectorOfInt.sizeOfVector());
    EXPECT_EQ(3, vectorOfInt2.sizeOfVector());
    EXPECT_EQ(0, vectorOfInt3.sizeOfVector());
}

TEST_F(VectorTest, capacityOfVector){
    EXPECT_EQ(10, vectorOfInt.capacityOfVector());
    EXPECT_EQ(8, vectorOfInt2.capacityOfVector());
    EXPECT_EQ(5, vectorOfInt3.capacityOfVector());
}

TEST_F(VectorTest, clearVectortest){
    vectorOfInt2.clearVector();
    EXPECT_TRUE(vectorOfInt2.isEmpty());
}

TEST_F(VectorTest, insertElementTest){
    vectorOfInt.insertElement(3,9);
    EXPECT_EQ(9, vectorOfInt[3]);
    vectorOfInt.insertElement(1,43);
    EXPECT_EQ(43, vectorOfInt[1]);
}

TEST_F(VectorTest, ereaseElementTest){
    vectorOfInt.ereaseElement(2);
    EXPECT_FALSE(vectorOfInt.search(3));
}

TEST_F(VectorTest, pushBackTest){
    vectorOfInt.pushBack(10);
    EXPECT_EQ(10, vectorOfInt.backElement());
}

TEST_F(VectorTest, popBackTest){
    vectorOfInt.popBack();
    EXPECT_EQ(4, vectorOfInt.backElement());
}
