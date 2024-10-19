/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:19:23 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 01:46:05 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This function performs a calculation based on the given input parameters.
 * It takes two integers as input and returns the result of the calculation.
 *
 * @param num1 The first integer input for the calculation.
 * @param num2 The second integer input for the calculation.
 * @return The result of the calculation.
 */
char	**get_map(char **raw_map_lines, size_t width, size_t height)
{
	char	**map;
	size_t	i;
	size_t	org_len;

	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	map[height] = NULL;
	i = 0;
	while (i < height)
	{
		map[i] = ft_calloc(width + 1, sizeof(char));
		if (map[i] == NULL)
		{
			free_map(map, i);
			return (NULL);
		}
		org_len = ft_strlcpy(map[i], raw_map_lines[i], width + 1);
		while (org_len < width)
			map[i][org_len++] = ' ';
		i++;
	}
	return (map);
}

/**
 * @brief Calculates the size of the map.
 *
 * This function takes an array of raw map lines and
 * calculates the width and height of the map.
 *
 * @param raw_map_lines The array of raw map lines.
 * @param width A pointer to store the width of the map.
 * @param height A pointer to store the height of the map.
 */
void	get_mapsize(char **raw_map_lines, size_t *width, size_t *height)
{
	size_t	max_width;
	size_t	tmp_width;
	size_t	i;

	i = 0;
	max_width = 0;
	if (raw_map_lines == NULL || *raw_map_lines == NULL)
		return ;
	*height = get_height(raw_map_lines);
	while (raw_map_lines[i] != NULL)
	{
		tmp_width = ft_strlen(raw_map_lines[i]);
		if (tmp_width > max_width)
			max_width = tmp_width;
		i ++;
	}
	*width = max_width;
}
