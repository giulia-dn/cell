//
// Created by giulia on 09/10/23.
//
#include "gtest/gtest.h"
#include "../CellBox.h"
#include "../Add.h"
#include "../Mean.h"


class MeanSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        a->addLista(0.5);
        a->addLista(2.5);
        a->addLista(-6);
    }

    Add *a = new Add;
    Mean m = Mean(a);
};

TEST_F(MeanSuite, TestOp) {
    m.op();
    ASSERT_EQ(-1, m.getR());
}

TEST_F(MeanSuite, TestReset) {
    m.reset();
    ASSERT_EQ(0, m.getR());
}

TEST(Mean, DefaultConstruct) {
    Add *a;
    Mean mean = Mean(a);
    ASSERT_EQ(0, mean.getR());

}