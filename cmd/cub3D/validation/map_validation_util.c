/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:25:39 by saraki            #+#    #+#             */
/*   Updated: 2024/10/17 16:29:58 by saraki           ###   ########.fr       */
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
