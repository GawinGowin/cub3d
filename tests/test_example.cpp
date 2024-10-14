#include <gtest/gtest.h>
// test_example.cpp
extern "C" {
    #include "example.h"
}

#include <gtest/gtest.h>

TEST(ExampleTest, AddFunction) {
    EXPECT_EQ(add(1, 2), 3);
}