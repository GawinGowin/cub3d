/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 06:17:26 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/28 17:03:38 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	detect_keys(int key, t_data *data)
{
	if (key == KEY_ESC)
		detect_close(data);
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		update_coordinate(data, key);
	else if (key == ARROW_R || key == ARROW_L)
		update_angle(data, key);
	else
		return (0);
	update_screen(data);
	printf("pos: (%f, %f)/ angle: %f\n",
		data->player.pos_x, data->player.pos_y, data->player.angle);
	return (0);
}

int	detect_close(t_data *data)
{
	deinit_exit(data, 0);
	return (0);
}
