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
	std::cout << "1" << std::endl;
	data.mlx_val.mlx_ptr = mlx_init();
	std::cout << "2" << std::endl;
	char** lines = create_test_lines();
	std::cout << "3" << std::endl;
	int ret = get_conf(&data, lines);
	std::cout << "4" << std::endl;
	EXPECT_EQ(ret, 0);
	std::cout << "5" << std::endl;
	EXPECT_EQ(data.params.floor, 0xdc6400);
	std::cout << "6" << std::endl;
	EXPECT_EQ(data.params.ceiling, 0xe11e00);
	std::cout << "7" << std::endl;
	EXPECT_NE(data.params.img_no, nullptr);
	std::cout << "8" << std::endl;
	EXPECT_NE(data.params.img_so, nullptr);
	std::cout << "9" << std::endl;
	EXPECT_NE(data.params.img_we, nullptr);
	std::cout << "10" <<std::endl;
	EXPECT_NE(data.params.img_ea, nullptr);
	std::cout << "11" <<std::endl;
	for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]);
    }
    free(lines);
	destroy_mlx_ptr(&data);
}