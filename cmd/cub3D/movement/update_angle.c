/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 04:20:45 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-15 04:20:45 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_angle(t_data *data, int key)
{
	int	now;

	now = data->player.angle;
	if (key == 65361)
		now -= 5;
	else if (key == 65363)
		now += 5;
	now = reset_angle(now);
	data->player.angle = now;
	printf("angle: %d\n", data->player.angle);
}

int	reset_angle(int now)
{
	if (now < 0)
		now = 360 + now;
	else if (now >= 360)
		now = now - 360;
	return (now);
}
