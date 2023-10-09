//
// Created by giulia on 09/10/23.
//
#include "gtest/gtest.h"
#include "../Add.h"

class AddSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        a.addLista(5.5);
        a.addLista(-7.9);
        a.addLista(0.1);
    }

    Add a;
};

TEST_F(AddSuite, TestGetR) {
    ASSERT_EQ(3, a.getR());

}

TEST_F(AddSuite, TestOp) {
    ASSERT_EQ(true, a.isNEmpty());
}

TEST_F(AddSuite, TestReset) {
    a.reset();
    ASSERT_EQ(false, a.isNEmpty());
}

TEST(Add, DefaultConstruct) {
    Add add;
    ASSERT_EQ(false, add.isNEmpty());
    //ASSERT_EQ(, add.getLista());
}