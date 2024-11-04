/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:14:23 by saraki            #+#    #+#             */
/*   Updated: 2024/11/04 04:30:52 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_screen(t_data *data)
{
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
	printf("pos_x: %f, pos_y: %f\n", data->player.pos_x, data->player.pos_y);
	return (0);
}
