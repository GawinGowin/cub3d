/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:25:39 by saraki            #+#    #+#             */
/*   Updated: 2024/10/16 06:42:24 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_invalid_char(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < get_height(map))
	{
		j = 0;
		while (j < get_width(map))
		{
			if (!ft_strchr(" 01NSEW", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**dup_map(char **map)
{
	char	**ret;
	size_t	i;
	size_t	height;

	height = get_height(map);
	ret = (char **)ft_calloc(sizeof(char *), (height + 1));
	if (!ret)
		return (NULL);
	ret[height] = NULL;
	i = 0;
	while (i < height)
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i])
		{
			free_map(ret, i);
			return (NULL);
		}
		i++;
	}
	return (ret);
}

void	free_map(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

size_t	get_width(char **map)
{
	return (ft_strlen(map[0]));
}
