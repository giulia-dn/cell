//
// Created by giulia on 09/10/23.
//
#include "gtest/gtest.h"
#include "../CellBox.h"
#include "../Add.h"
#include "../Sum.h"


class SumSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        a->addLista(0.5);
        a->addLista(2.5);
        a->addLista(-7);
    }

    Add *a = new Add;
    Sum s = Sum(a);
};

TEST_F(SumSuite, TestOp) {
    s.op();
    ASSERT_EQ(-4, s.getR());
}

TEST_F(SumSuite, TestReset) {
    s.reset();
    ASSERT_EQ(0, s.getR());
}

TEST(Sum, DefaultConstruct) {
    Add *a;
    Sum sum = Sum(a);
    ASSERT_EQ(0, sum.getR());

}