/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:20:45 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/28 16:55:03 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_angle(t_data *data, int key)
{
	double	now;
	t_dda	dda_ret;

	now = data->player.angle;
	if (key == ARROW_L)
		now -= 5;
	else if (key == ARROW_R)
		now += 5;
	now = regulate_angle(now);
	data->player.angle = now;
	dda_ret = dda(&data->player, data->params.map);
	if (dda_ret.is_hit == 1)
		printf("hitblock: (%zu, %zu)/ distance: %f\n", dda_ret.hit_block[0], dda_ret.hit_block[1], dda_ret.distance);
}

double	regulate_angle(double now)
{
	while (now < 0)
		now = 360.0 + now;
	while (now >= 360.0)
		now = now - 360.0;
	return (now);
}
