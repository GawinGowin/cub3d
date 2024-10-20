/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:25:39 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 19:35:29 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_surrounded(
				char **map, char **memory, size_t height, size_t width);
static int	check_surrounding(
				char **map, char **memory, size_t height, size_t width);
static void	dfs(char **map, char **memory, size_t x, size_t y);

/**
 * @brief Validates the given map.
 *
 * This function checks if the provided map is valid according to the game's
 * rules and requirements. The map is represented as a 2D array of characters.
 *
 * @param map A 2D array of characters representing the map to be validated.
 * e.g.:
 * char **map = {
 *         "111   ",
 *         "101111",
 *         "100001",
 *         "111111",
 *         NULL
 *     };
 * @return An integer indicating whether the map is valid (1) or not (0).
 */
int	is_valid_map(char **map)
{
	char	**memory;
	int		ret;
	size_t	height;
	size_t	width;

	if (map == NULL || *map == NULL)
		return (0);
	height = get_height(map);
	width = get_width(map);
	if (has_invalid_char(map, " 01NSEW"))
		return (0);
	memory = dup_map(map, height);
	if (!memory)
		return (0);
	ret = is_surrounded(map, memory, height, width);
	free_map(memory, height);
	if (!ret)
		return (0);
	if (!is_contain_only_one_symbol(map, "NSEW", height, width))
		return (0);
	return (ret);
}

static int	is_surrounded(
				char **map, char **memory, size_t height, size_t width)
{
	size_t	x;
	size_t	y;
	int		ret;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == WALL || map[y][x] == SPACE)
			{
				x++;
				continue ;
			}
			dfs(map, memory, x, y);
			x++;
		}
		y++;
	}
	ret = check_surrounding(map, memory, height, width);
	return (ret);
}

static int	check_surrounding(
				char **map, char **memory, size_t height, size_t width)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((memory[y][x] == (char) 1
				&& (map[y][x] == ' ' || x == 0
				|| x == width - 1 || y == 0 || y == height - 1)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	dfs(char **map, char **memory, size_t x, size_t y)
{
	size_t	height;
	size_t	width;

	if (map[y][x] == WALL || memory[y][x] == (char) 1)
		return ;
	memory[y][x] = (char) 1;
	width = get_width(map);
	height = get_height(map);
	if (x != 0 && x - 1 < width && y < height)
		dfs(map, memory, x - 1, y);
	if (x + 1 < width && y < height)
		dfs(map, memory, x + 1, y);
	if (x < width && y != 0 && y - 1 < height)
		dfs(map, memory, x, y - 1);
	if (x < width && y + 1 < height)
		dfs(map, memory, x, y + 1);
	return ;
}
