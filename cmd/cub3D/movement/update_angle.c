/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:20:45 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 04:58:09 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_angle(t_data *data, int key)
{
	double	now;

	now = data->player.angle;
	if (key == XK_Left)
		now -= ROTATION;
	else if (key == XK_Right)
		now += ROTATION;
	now = regulate_angle(now);
	data->player.angle = now;
}

double	regulate_angle(double now)
{
	while (now < 0)
		now = 360.0 + now;
	while (now >= 360.0)
		now = now - 360.0;
	return (now);
}
