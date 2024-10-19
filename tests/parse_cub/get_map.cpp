#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

TEST(GetMapTest, GetMap)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("010");
	raw_map_lines[2] = strdup("111");

	size_t width = 3;
	size_t height = 3;

	char **map = get_map(raw_map_lines, width, height);

	EXPECT_STREQ(map[0], "111");
	EXPECT_STREQ(map[1], "010");
	EXPECT_STREQ(map[2], "111");

	free_map(raw_map_lines, 3);
	free_map(map, 3);
}

TEST(GetMapTest, GetMapWithEmptyLines)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("");
	raw_map_lines[2] = strdup("111");

	size_t width = 3;
	size_t height = 3;

	char **map = get_map(raw_map_lines, width, height);

	EXPECT_STREQ(map[0], "111");
	EXPECT_STREQ(map[1], "   ");
	EXPECT_STREQ(map[2], "111");

	free_map(raw_map_lines, 3);
	free_map(map, 3);
}

TEST(GetMapTest, GetMapWithLongerLines)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("0101");
	raw_map_lines[2] = strdup("111");

	size_t width = 3;
	size_t height = 3;

	char **map = get_map(raw_map_lines, width, height);

	EXPECT_STREQ(map[0], "111");
	EXPECT_STREQ(map[1], "010");
	EXPECT_STREQ(map[2], "111");

	free_map(raw_map_lines, 3);
	free_map(map, 3);
}

TEST(GetMapSizeTest, GetMapSize)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("010");
	raw_map_lines[2] = strdup("111");

	size_t width;
	size_t height;

	get_mapsize(raw_map_lines, &width, &height);

	EXPECT_EQ(width, 3);
	EXPECT_EQ(height, 3);

	free_map(raw_map_lines, 3);
}

TEST(GetMapSizeTest, GetMapSizeWithEmptyLines)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("");
	raw_map_lines[2] = strdup("111");

	size_t width;
	size_t height;

	get_mapsize(raw_map_lines, &width, &height);

	EXPECT_EQ(width, 3);
	EXPECT_EQ(height, 3);

	free_map(raw_map_lines, 3);
}

TEST(GetMapSizeTest, GetMapSizeWithLongerLines)
{
	char **raw_map_lines = (char **)malloc(sizeof(char *) * 3);
	raw_map_lines[0] = strdup("111");
	raw_map_lines[1] = strdup("0101");
	raw_map_lines[2] = strdup("111");

	size_t width;
	size_t height;

	get_mapsize(raw_map_lines, &width, &height);

	EXPECT_EQ(width, 4);
	EXPECT_EQ(height, 3);

	free_map(raw_map_lines, 3);
}