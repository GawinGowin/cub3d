/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:14:23 by saraki            #+#    #+#             */
/*   Updated: 2024/11/03 17:19:10 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_screen(t_data *data)
{
	/* renderring calcuration start */
	render_bg(&(data->mlx_val), data->params.ceiling, data->params.floor);
	if (render_walls(data, &(data->player)))
	{
		printerror(ERR_FAILED_RENDERING);
		deinit_exit(data, 1);
	}
	/* renderring calcuration end */
	if (render_image(&(data->mlx_val)))
	{
		printerror(ERR_FAILED_RENDERING);
		deinit_exit(data, 1);
	}
	return ;
}
