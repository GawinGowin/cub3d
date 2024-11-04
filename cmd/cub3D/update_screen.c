/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:14:23 by saraki            #+#    #+#             */
/*   Updated: 2024/11/04 05:00:13 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_screen(t_data *data)
{
	if (data->is_moving == 0)
		return (0);
	render_bg(&(data->mlx_val), data->params.ceiling, data->params.floor);
	if (render_walls(data, &(data->player)))
	{
		printerror(ERR_FAILED_RENDERING);
		deinit_exit(data, 1);
	}
	if (render_image(&(data->mlx_val)))
	{
		printerror(ERR_FAILED_RENDERING);
		deinit_exit(data, 1);
	}
	printf("pos_x: %f, pos_y: %f, rotation: %f\n",
		data->player.pos_x, data->player.pos_y, data->player.angle);
	return (0);
}
