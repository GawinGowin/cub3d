/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:53:37 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/27 09:40:42 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_values(t_data *data);

int	init_data(t_data *data, char *name)
{
	init_values(data);
	if (init_mlx_ptr(data, name))
		return (printerror(ERR_FAILED_INIT_MLX));
	return (0);
}

static void	init_values(t_data *data)
{
	data->player.pos_x = 0.0;
	data->player.pos_y = 0.0;
	data->player.angle = 0;
	data->mlx_val.bpp = 0;
	data->mlx_val.endian = 0;
	data->mlx_val.line_byte = 0;
	data->mlx_val.mlx_ptr = NULL;
	data->mlx_val.win_ptr = NULL;
	data->mlx_val.img_ptr = NULL;
	data->mlx_val.addr = NULL;
	data->params.map_width = 0;
	data->params.map_height = 0;
	data->params.map = NULL;
	data->params.img_no = NULL;
	data->params.img_so = NULL;
	data->params.img_we = NULL;
	data->params.img_ea = NULL;
	data->params.ceiling = -1;
	data->params.floor = -1;
}
