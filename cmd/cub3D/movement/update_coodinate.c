/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coodinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:43:41 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/21 08:43:02 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_coordinate(t_data *data, int key)
{
	int		angle;
	double	delta[2];
	t_dda	dda_ret;

	angle = data->player.angle;
	if (key == KEY_D)
		angle += 90;
	else if (key == KEY_A)
		angle -= 90;
	else if (key == KEY_S)
		angle += 180;
	angle = regulate_angle(angle);
	(void) dda_ret;
	dda_ret = dda(&data->player, data->params.map);
	if (dda_ret.is_hit == 1)
		printf("hitblock: (%zu, %zu)/ distance: %f\n", dda_ret.hit_block[0], dda_ret.hit_block[1], dda_ret.distance);
	delta[0] = STRIDE * cos_degree(angle);
	delta[1] = STRIDE * sin_degree(angle);
	if (dda_ret.distance > sqrt((delta[0] * delta[0]) + (delta[1] * delta[1])))
	{
		data->player.pos_x += delta[0];
		data->player.pos_y += delta[1];
	}
	// else if ()
	// {
	// 	data->player.pos_x += floor(dda_ret.distance * cos_degree(angle));
	// 	data->player.pos_y += floor(dda_ret.distance * sin_degree(angle));
	// }

}
