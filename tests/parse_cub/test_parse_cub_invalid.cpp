#include <gtest/gtest.h>

extern "C"
{
	#include "cub3d.h"
}

#include "compare_operators.h"

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
			EXPECT_EQ(is_valid_map((char **)data.params.map), 0);
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
            .cub_file_path = (char*)"examples/bad/color_invalid_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/color_missing_ceiling_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/color_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/color_missing_floor_rgb.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/color_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/empty.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/file_letter_end.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/filetype_missing",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/filetype_wrong.buc",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/map_first.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/map_middle.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/map_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/map_only.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/map_too_small.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/player_multiple.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/player_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/player_on_edge.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_dir.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_duplicates.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_invalid.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_missing.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/wall_hole_east.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/wall_hole_north.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/wall_hole_south.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/wall_hole_west.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/wall_none.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_not_xpm.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/textures_forbidden.cub",
        },
        CubErrTestData{
            .cub_file_path = (char*)"examples/bad/forbidden.cub",
        }
    )
);