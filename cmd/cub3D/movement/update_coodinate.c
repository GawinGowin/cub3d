/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coodinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 07:43:41 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-18 07:43:41 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_coordinate(t_data *data, int key)
{
	int		angle;
	double	x;
	double	y;

	angle = data->player.angle;
	if (key == KEY_D)
		angle += 90;
	else if (key == KEY_A)
		angle -= 90;
	else if (key == KEY_S)
		angle += 180;
	angle = regulate_angle(angle);
	x = data->player.pos_x + STRIDE * cos_degree(angle);
	y = data->player.pos_y + STRIDE * sin_degree(angle);
	if (0 <= x && x < data->params.map_width)
		if (data->params.map[(int)(x + 0.5)][(int)(y + 0.5)] != WALL)
			data->player.pos_x = x;
	if (0 <= y && y < data->params.map_height)
		if (data->params.map[(int)(x + 0.5)][(int)(y + 0.5)] != WALL)
			data->player.pos_y = y;
}
