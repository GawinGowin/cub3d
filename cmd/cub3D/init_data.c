/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 06:53:37 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-12 06:53:37 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_values(t_data *data);
static int	init_mlx_ptr(t_data *data, char *name);

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

static int	init_mlx_ptr(t_data *data, char *name)
{
	data->mlx_val.mlx_ptr = mlx_init();
	if (!data->mlx_val.mlx_ptr)
		return (1);
	data->mlx_val.win_ptr = mlx_new_window(data->mlx_val.mlx_ptr, WIN_WIDTH, \
			WIN_HEIGHT, name);
	if (!data->mlx_val.win_ptr)
		return (destroy_mlx_ptr(data));
	data->mlx_val.img_ptr = mlx_new_image(data->mlx_val.mlx_ptr, WIN_WIDTH, \
			WIN_HEIGHT);
	if (!data->mlx_val.img_ptr)
		return (destroy_mlx_ptr(data));
	data->mlx_val.addr = mlx_get_data_addr(data->mlx_val.img_ptr, \
			&data->mlx_val.bpp, &data->mlx_val.line_byte, \
			&data->mlx_val.endian);
	if (!data->mlx_val.addr)
		return (destroy_mlx_ptr(data));
	return (0);
}
