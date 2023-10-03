#include "gtest/gtest.h"
#include "../CellBox.h"


TEST(CellBox, DefaultConstruct) {
    CellBox cb;
    ASSERT_EQ(0, cb.getAddResult());
    ASSERT_EQ(0, cb.getMeanResult());
    ASSERT_EQ(0, cb.getMaxResult());
    ASSERT_EQ(0, cb.getMinResult());
}

TEST(CellBox, TestSet) {
    CellBox cb;
    cb.setAddResult(3);
    ASSERT_EQ(3, cb.getAddResult());
    cb.setMeanResult(-4);
    ASSERT_EQ(-4, cb.getMeanResult());
    cb.setMaxResult(100);
    ASSERT_EQ(100, cb.getMaxResult());
    cb.setMinResult(7);
    ASSERT_EQ(7, cb.getMinResult());

}