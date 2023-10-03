#include "gtest/gtest.h"
#include "../CellBox.h"
#include "../Cell.h"


class CellBoxSuite : public ::testing::Test {
public:
    virtual void SetUp() {
        Cell *c = new Cell(3);
        Cell *c1 = new Cell(4);
        cb.addCell(c);
        cb.addCell(c1);

    }

    CellBox cb;
};

TEST_F(CellBoxSuite, TestSum) {
    cb.sum();
    ASSERT_EQ(7, cb.getAddResult());
}

TEST_F(CellBoxSuite, TestMean) {
    cb.mean();
    ASSERT_EQ(-1, cb.getMeanResult());
}

TEST_F(CellBoxSuite, TestMax) {
    cb.max();
    ASSERT_EQ(4, cb.getMaxResult());
}

TEST_F(CellBoxSuite, TestMin) {
    cb.min();
    ASSERT_EQ(3, cb.getMinResult());
}
