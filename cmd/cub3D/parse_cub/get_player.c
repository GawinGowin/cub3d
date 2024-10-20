/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:51:37 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 16:08:37 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_from_char(t_data *data, char symbol, int y, int x);

int	get_player(t_data *data)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = data->params.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (get_player_from_char(data, map[y][x], y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	get_player_from_char(t_data *data, char symbol, int y, int x)
{
	if (symbol == PLAYER_NORTH)
		data->player.angle = 270;
	else if (symbol == PLAYER_SOUTH)
		data->player.angle = 90;
	else if (symbol == PLAYER_WEST)
		data->player.angle = 180;
	else if (symbol == PLAYER_EAST)
		data->player.angle = 0;
	else
		return (0);
	data->player.pos_x = x;
	data->player.pos_y = y;
	return (1);
}
