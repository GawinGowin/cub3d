/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:25:39 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 18:30:01 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_contain_only_one_symbol_inline(
				char *line, char *set, int *flag, size_t width);

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

int	is_contain_only_one_symbol(char **map, char *set, size_t height, size_t width)
{
	size_t	y;
	size_t	i;
	size_t	set_len;
	int		flag;
	int		flag_all;

	if (set == NULL || *set == '\0' || map == NULL || *map == NULL)
		return (0);
	i = 0;
	flag = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
		flag |= (1 << i ++);
	flag_all = flag;
	y = 0;
	while (y < height)
	{
		if (is_contain_only_one_symbol_inline(map[y], set, &flag, width) == 0)
			return (0);
		y ++;
	}
	return (flag != flag_all);
}

static int	is_contain_only_one_symbol_inline(
				char *line, char *set, int *flag, size_t width)
{
	size_t	x;
	char	*pt;
	int		index;

	x = 0;
	while (x < width)
	{
		pt = ft_strchr(set, line[x]);
		if (pt != NULL)
		{
			index = pt - set;
			if (*flag & (1 << index))
				(*flag) &= ~(1 << index);
			else
				return (0);
		}
		x ++;
	}
	return (1);
}
