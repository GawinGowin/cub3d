#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

struct CubTestData
{
	char *cub_file_path;
	void *expected_img_no;
	void *expected_img_so;
	void *expected_img_we;
	void *expected_img_ea;
	int expected_floor;
	int expected_ceiling;
	size_t expected_map_width;
	size_t expected_map_height;
	const char *expected_map[100];
};

bool operator==(const t_param_cub &a, const t_param_cub &b) {
    if (a.floor != b.floor || a.ceiling != b.ceiling) {
        return false;
    }
    if (a.map_width != b.map_width || a.map_height != b.map_height) {
        return false;
    }
    for (size_t i = 0; i < a.map_height; i++) {
        if (strcmp(a.map[i], b.map[i]) != 0) {
            return false;
        }
    }
    return true;
}

class CubInputTest : public ::testing::TestWithParam<CubTestData>
{
};

TEST_P(CubInputTest, CubInput)
{
	auto param = GetParam();
	t_data data = {};
	t_param_cub expected_data = {
		.img_no = param.expected_img_no,
		.img_so = param.expected_img_so,
		.img_we = param.expected_img_we,
		.img_ea = param.expected_img_ea,
		.floor = param.expected_floor,
		.ceiling = param.expected_ceiling,
		.map_width = param.expected_map_width,
		.map_height = param.expected_map_height,
		.map = (char **) param.expected_map,
	};
	parse_cub(&data, param.cub_file_path);
	EXPECT_EQ(data.params, expected_data);
	free_2d_array_of_char(data.params.map);
}

INSTANTIATE_TEST_SUITE_P(
    LoadCubFile,
    CubInputTest,
    ::testing::Values(
        CubTestData{
            .cub_file_path = (char*)"examples/test1.cub",
			.expected_img_no = (void*)0,
			.expected_img_so = (void*)0,
			.expected_img_we = (void*)0,
			.expected_img_ea = (void*)0,
            .expected_floor = 14443520,
            .expected_ceiling = 14753280,
            .expected_map_width = 33,
            .expected_map_height = 14,
            .expected_map = {
				"        1111111111111111111111111",
				"        1000000000110000000000001",
				"        1011000001110000000000001",
				"        1001000000000000000000001",
				"111111111011000001110000000000001",
				"100000000011000001110111111111111",
				"11110111111111011100000010001    ",
				"11110111111111011101010010001    ",
				"11000000110101011100000010001    ",
				"10000000000000001100000010001    ",
				"10000000000000001101010010001    ",
				"11000001110101011111011110N0111  ",
				"11110111 1110101 101111010001    ",
				"11111111 1111111 111111111111    ",
				NULL
            }
        }
    )
);