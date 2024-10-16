#include <gtest/gtest.h>

extern "C" {
    #include "cub3d.h"
}

TEST(MapValidation, MapOK1) {
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
	EXPECT_EQ(is_valid_map((char **)map), 1);
}

TEST(MapValidation, MapOK2) {
	const char *map[] = {
		"11111111",
		"10000001",
		"10000001",
		"10000001",
		"10000111",
		"100001  ",
		"111111  ",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 1);
}

TEST(MapValidation, MapOK3) {
	const char *map[] = {
		"  111111",
		"  100001",
		"11100001",
		"10000001",
		"10000111",
		"100001  ",
		"111111  ",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 1);
}

TEST(MapValidation, MapOK4) {
	const char *map[] = {
		"  111111",
		"  100111",
		"11100001",
		"10000001",
		"10000111",
		"111001  ",
		"111111  ",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 1);
}

TEST(MapValidation, MapOK5) {
	const char *map[] = {
		"        ",
		" 111111 ",
		" 100001 ",
		" 100001 ",
		" 100001 ",
		" 111111 ",
		"        ",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 1);
}


TEST(MapValidation, MapERR1) {
	const char *map[] = {
		"11111111",
		"10000001",
		"10000001",
		"1000000 ",
		"10000001",
		"10000001",
		"11111111",
		NULL
	};
	int ret = is_valid_map((char **)map);
	EXPECT_EQ(ret, 0);
}

TEST(MapValidation, MapERR2) {
	const char *map[] = {
		"11111111",
		"10000001",
		"10000000",
		"10000000",
		"10000001",
		"10000001",
		"11111111",
		NULL
	};
	int ret = is_valid_map((char **)map);
	EXPECT_EQ(ret, 0);
}


TEST(MapValidation, MapERR3) {
	const char *map[] = {
		"        ",
		"        ",
		"        ",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 0);
}

TEST(MapValidation, MapERR4) {
	const char *map[] = {
		"1111111111",
		"1111111111",
		"1111111111",
		NULL
	};
	EXPECT_EQ(is_valid_map((char **)map), 0);
}