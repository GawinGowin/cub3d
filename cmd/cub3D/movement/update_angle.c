/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:20:45 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/21 08:46:20 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_angle(t_data *data, int key)
{
	int		now;
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

int	regulate_angle(int now)
{
	if (now < 0)
		now = 360 + now;
	else if (now >= 360)
		now = now - 360;
	return (now);
}
