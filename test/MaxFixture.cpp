//
// Created by giulia on 09/10/23.
//

//
// Created by giulia on 09/10/23.
//
#include "gtest/gtest.h"
#include "../CellBox.h"
#include "../Add.h"
#include "../Max.h"


class MaxSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        a->addLista(0.5);
        a->addLista(2.5);
        a->addLista(-6);
    }

    Add *a = new Add;
    Max mx = Max(a);
};

TEST_F(MaxSuite, TestOp) {
    mx.op();
    ASSERT_EQ(2.5, mx.getR());
}

TEST_F(MaxSuite, TestReset) {
    mx.reset();
    ASSERT_EQ(0, mx.getR());
}

TEST(Max, DefaultConstruct) {
    Add *a;
    Max max = Max(a);
    ASSERT_EQ(0, max.getR());

}