#include <gtest/gtest.h>

extern "C"
{
#include "cub3d.h"
}

TEST(DupMapTest, DuplicateMap)
{
	char **originalMap = (char **)malloc(sizeof(char *) * 3);
	originalMap[0] = strdup("111");
	originalMap[1] = strdup("010");
	originalMap[2] = strdup("111");

	char **duplicatedMap = dup_map(originalMap, 3);

	EXPECT_STREQ(duplicatedMap[0], "111");
	EXPECT_STREQ(duplicatedMap[1], "010");
	EXPECT_STREQ(duplicatedMap[2], "111");

	free_map(originalMap, 3);
	free_map(duplicatedMap, 3);
}

TEST(FreeMapTest, FreeMap)
{
	char **map = (char **)malloc(sizeof(char *) * 3);
	map[0] = strdup("111");
	map[1] = strdup("010");
	map[2] = strdup("111");

	free_map(map, 3);
}

TEST(GetHeightTest, GetMapHeight)
{
	char **map = (char **)malloc(sizeof(char *) * 3);
	map[0] = strdup("111");
	map[1] = strdup("010");
	map[2] = strdup("111");

	size_t height = get_height(map);

	EXPECT_EQ(height, 3);

	free_map(map, 3);
}

TEST(GetHeightTest, GetNULLMapHeight)
{
	char **map = NULL;

	size_t height = get_height(map);

	EXPECT_EQ(height, 0);
}

TEST(GetHeightTest, GetNULLLineMapHeight)
{
	char **map = (char **)malloc(sizeof(char *) * 3);
	map[0] = NULL;
	map[1] = NULL;
	map[2] = NULL;

	size_t height = get_height(map);

	EXPECT_EQ(height, 0);
	free_map(map, 3);
}

TEST(GetWidthTest, GetMapWidth)
{
	char **map = (char **)malloc(sizeof(char *) * 3);
	map[0] = strdup("111");
	map[1] = strdup("010");
	map[2] = strdup("111");

	size_t width = get_width(map);

	EXPECT_EQ(width, 3);

	free_map(map, 3);
}

TEST(GetWidthTest, GetNULLMapWidth)
{
	char **map = NULL;

	size_t width = get_width(map);

	EXPECT_EQ(width, 0);
}

TEST(GetWidthTest, GetNULLLineMapWidth)
{
	char **map = (char **)malloc(sizeof(char *) * 3);
	map[0] = NULL;
	map[1] = NULL;
	map[2] = NULL;

	size_t width = get_width(map);

	EXPECT_EQ(width, 0);
	free_map(map, 3);
}
