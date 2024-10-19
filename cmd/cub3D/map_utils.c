/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:30:11 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 02:55:24 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Duplicates a 2D map array.
 *
 * This function creates a duplicate of a given 2D map array. It allocates
 * memory for the new map and copies the contents from the original map.
 *
 * @param map The original 2D map array to be duplicated.
 * @param height The number of rows in the map.
 * @return A pointer to the newly allocated and duplicated 2D map array.
 */
char	**dup_map(char **map, size_t height)
{
	char	**ret;
	size_t	i;

	if (!map || !*map || get_height(map) < height)
		return (NULL);
	ret = (char **)ft_calloc(sizeof(char *), (height + 1));
	if (!ret)
	{
		printerror(ERR_MALLOC);
		return (NULL);
	}
	ret[height] = NULL;
	i = 0;
	while (i < height)
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i])
		{
			free_map(ret, i);
			printerror(ERR_MALLOC);
			return (NULL);
		}
		i++;
	}
	return (ret);
}

/**
 * @brief Frees the memory allocated for a 2D map array.
 *
 * This function iterates through each row of the map and frees the memory
 * allocated for it. Finally, it frees the memory allocated for the map itself.
 *
 * @param map A pointer to the 2D array representing the map.
 * @param height The number of rows in the map.
 */
void	free_map(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

/**
 * @brief Get the height of the map.
 *
 * This function calculates the number of rows in the given map.
 *
 * @param map A pointer to an array of strings representing the map.
 * @return The height of the map as a size_t value.
 */
size_t	get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map && *map && map[i])
		i++;
	return (i);
}

/**
 * @brief Get the width of the map.
 *
 * This function calculates the width of the map by determining the length
 * of the longest string in the provided 2D array of characters.
 *
 * @param map A 2D array of characters representing the map.
 * @return The width of the map.
 */
size_t	get_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}
