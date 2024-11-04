#include <gtest/gtest.h>

extern "C"
{
	#include "cub3d.h"
}

#include "compare_operators.hpp"

struct CubErrTestData
{
	char *cub_file_path;
};

class CubErrInputTest : public ::testing::TestWithParam<CubErrTestData>
{
};

TEST_P(CubErrInputTest, CubErrInput)
{
	auto param = GetParam();
	t_data data = {};
	t_texture img_void = {};
	data.mlx_val.mlx_ptr = mlx_init();
	if (data.mlx_val.mlx_ptr != NULL) {
		t_param_cub expected_data = {
			.img_no = img_void,
			.img_so = img_void,
			.img_we = img_void,
			.img_ea = img_void,
			.floor = -1,
			.ceiling = -1,
			.map_width = 0,
			.map_height = 0,
			.map = (char **) nullptr,
		};
		t_player expected_player = {
			.pos_x = 0,
			.pos_y = 0,
			.angle = 0,
		};
		std::cout << "cub_file_path: " << param.cub_file_path << std::endl;
		int ret = parse_cub(&data, param.cub_file_path);
		if (ret == 0) {
			int is_valid = is_validate(&data);
			EXPECT_EQ(is_valid, 0);
		}
		else {
			EXPECT_EQ(data.params, expected_data);
			EXPECT_EQ(data.player, expected_player);
		}
		if (data.params.map != NULL) {
			free_2d_array_of_char(data.params.map);
		}
		destroy_mlx_ptr(&data);
	}
}

INSTANTIATE_TEST_SUITE_P(
    InvaildCubFiles,
    CubErrInputTest,
    ::testing::Values(
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_color_invalid_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_color_missing_ceiling_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_color_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_color_missing_floor_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_color_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_empty.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_file_letter_end.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_map_first.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_map_middle.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_map_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_map_only.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_map_too_small.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_player_multiple.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_player_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_player_on_edge.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_dir.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_duplicates.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_invalid.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_wall_hole_east.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_wall_hole_north.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_wall_hole_south.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_wall_hole_west.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_wall_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/test/bad_textures_forbidden.cub",
        }
    )
);