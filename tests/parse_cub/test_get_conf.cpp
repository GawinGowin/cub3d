#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

char** create_test_lines() {
	char** lines = (char**)malloc(sizeof(char*) * 7);
	lines[0] = strdup("NO ./assets/north_compass.xpm");
	lines[1] = strdup("SO ./assets/south_compass.xpm");
	lines[2] = strdup("WE ./assets/west_compass.xpm");
	lines[3] = strdup("EA ./assets/east_compass.xpm");
	lines[4] = strdup("F 220,100,0");
	lines[5] = strdup("C 225,30,0");
	lines[6] = NULL;
	return lines;
}

TEST(GetConfTest, GetConf)
{
	t_data data = {};
	data.mlx_val.mlx_ptr = mlx_init();
	char** lines = create_test_lines();
	int ret = get_conf(&data, lines);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(data.params.floor, 0xdc6400);
	EXPECT_EQ(data.params.ceiling, 0xe11e00);
	EXPECT_NE(data.params.img_no, nullptr);
	EXPECT_NE(data.params.img_so, nullptr);
	EXPECT_NE(data.params.img_we, nullptr);
	EXPECT_NE(data.params.img_ea, nullptr);
	for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]);
    }
    free(lines);
	destroy_mlx_ptr(&data);
}