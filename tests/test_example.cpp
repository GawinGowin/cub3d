#include <gtest/gtest.h>

extern "C" {
    #include "example.h"
}

TEST(ExampleTest, AddFunction) {
    EXPECT_EQ(add(1, 2), 3);
}