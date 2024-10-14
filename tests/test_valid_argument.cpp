#include <gtest/gtest.h>
extern "C" {
    #include "cub3d.h"  // Include the C header
}

// Example test case
TEST(ValidArgumentTest, HandlesValidInput) {
    EXPECT_TRUE(is_valid_map("some_valid_input"));
}

TEST(ValidArgumentTest, HandlesInvalidInput) {
    EXPECT_FALSE(is_valid_map("invalid_input"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}