#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

struct MapTestData
{
	const char *map[10];
	int expected; // 期待される結果
};

// テストデータの作成
class MapValidationTest : public ::testing::TestWithParam<MapTestData>
{
};

TEST_P(MapValidationTest, ValidateMap)
{
	auto param = GetParam();
	EXPECT_EQ(is_valid_map((char **)param.map), param.expected);
}

// 有効なマップ
INSTANTIATE_TEST_SUITE_P(
	ValidMaps,
	MapValidationTest,
	::testing::Values(
		MapTestData{{"11111111",
					 "10000001",
					 "10000001",
					 "10000001",
					 "10000001",
					 "10000001",
					 "11111111", NULL},
					1},
		MapTestData{{"11111111",
					 "10000001",
					 "10000001",
					 "10000111",
					 "100001  ",
					 "111111  ", NULL},
					1},
		MapTestData{{"  111111",
					 "  100001",
					 "11100001",
					 "10000001",
					 "10000111",
					 "100001  ",
					 "111111  ", NULL},
					1}
	)
);

INSTANTIATE_TEST_SUITE_P(
	InvalidMaps,
	MapValidationTest,
	::testing::Values(
		MapTestData{{"11111111",
					 "10000001",
					 "10000001",
					 "1000000 ",
					 "10000001",
					 "11111111", NULL},
					0},
		MapTestData{{"        ",
					 "        ",
					 "        ",
					 NULL},
					0},
		MapTestData{{"1111111111",
					 "1111111111",
					 "1111111111",
					 NULL},
					0},
		MapTestData{{"1111111111",
					 NULL},
					0},
		MapTestData{{"1",
					 "1",
					 "1",
					 "1",
					 "1",
					 "1",
					 NULL},
					0}
	)
);