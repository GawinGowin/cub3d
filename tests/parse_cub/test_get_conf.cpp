#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

use namespace std;

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
	cout << "1" << endl;
	data.mlx_val.mlx_ptr = mlx_init();
	cout << "2" << endl;
	char** lines = create_test_lines();
	cout << "3" << endl;
	int ret = get_conf(&data, lines);
	cout << "4" << endl;
	EXPECT_EQ(ret, 0);
	cout << "5" << endl;
	EXPECT_EQ(data.params.floor, 0xdc6400);
	cout << "6" << endl;
	EXPECT_EQ(data.params.ceiling, 0xe11e00);
	cout << "7" << endl;
	EXPECT_NE(data.params.img_no, nullptr);
	cout << "8" << endl;
	EXPECT_NE(data.params.img_so, nullptr);
	cout << "9" << endl;
	EXPECT_NE(data.params.img_we, nullptr);
	cout << "10" << endl;
	EXPECT_NE(data.params.img_ea, nullptr);
	cout << "11" << endl;
	for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]);
    }
    free(lines);
	destroy_mlx_ptr(&data);
}