#include <gtest/gtest.h>

extern "C" {
    #include "cub3d.h"
}

TEST(MapValidation, MapOK) {
	const char *map[] = {
		"11111111",
		"10000001",
		"10000001",
		"10000001",
		"10000001",
		"10000001",
		"11111111",
		NULL
	};
	EXPECT_TRUE(is_valid_map((char **)map));
}

TEST(MapValidation, MapKO) {
	const char *map[] = {
		"11111111",
		"10000001",
		"10000000",
		"10000001",
		"10000001",
		"10000001",
		"11111111",
		NULL
	};
	EXPECT_FALSE(is_valid_map((char **)map));
}
