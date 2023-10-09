//
// Created by giulia on 09/10/23.
//
#include "gtest/gtest.h"
#include "../CellBox.h"
#include "../Add.h"
#include "../Min.h"


class MinSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        a->addLista(0.5);
        a->addLista(2.5);
        a->addLista(-6);
    }

    Add *a = new Add;
    Min mn = Min(a);
};

TEST_F(MinSuite, TestOp) {
    mn.op();
    ASSERT_EQ(-6, mn.getR());
}

TEST_F(MinSuite, TestReset) {
    mn.reset();
    ASSERT_EQ(0, mn.getR());
}

TEST(Min, DefaultConstruct) {
    Add *a;
    Min min = Min(a);
    ASSERT_EQ(0, min.getR());
}