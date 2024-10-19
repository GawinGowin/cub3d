#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

struct CubTestData
{
	char *cub_file_path;
	t_param_cub	expected;
};

// テストデータの作成
class CubInputTest : public ::testing::TestWithParam<CubTestData>
{
};

TEST_P(CubInputTest, CubInput)
{
	auto param = GetParam();
	t_param_cub data = {};
	parse_cub(&data, param.cub_file_path);
	EXPECT_EQ(data, param.expected);
}

INSTANTIATE_TEST_SUITE_P(
	LoadCubFile,
	CubInputTest,
	::testing::Values(
		CubTestData{"examples/test1.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/test2.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/test3.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/test4.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/test5.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/test6.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}},
		CubTestData{"examples/blank.cub",
					(t_param_cub){
						.img_we = NULL,
						.img_ea = NULL,
						.floor = 0,
						.ceiling = 0,
						.map_width = 3,
						.map_height = 3,
						.map = (char **)malloc(sizeof(char *) * 3),
					}}
	)
);
