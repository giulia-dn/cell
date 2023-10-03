#include "gtest/gtest.h"
#include "../Cell.h"

TEST(Cell, DefaultContructor) {
    Cell c(0);
    ASSERT_EQ(0, c.getData());
}

