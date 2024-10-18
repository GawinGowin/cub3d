/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:30:11 by saraki            #+#    #+#             */
/*   Updated: 2024/10/18 11:21:41 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**dup_map(char **map, size_t height)
{
	char	**ret;
	size_t	i;

	if (!map && !*map)
		return (NULL);
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
	while (map && map[i])
		i++;
	return (i);
}

size_t	get_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}
