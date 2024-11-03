/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:53:37 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/03 01:21:36 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx_ptr(t_data *data, char *name);
static void	init_values(t_data *data);

int	init_data(t_data *data, char *name)
{
	init_values(data);
	if (init_mlx_ptr(data, name))
		return (printerror(ERR_FAILED_INIT_MLX));
	return (0);
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
	data->params.img_no.img = NULL;
	data->params.img_so.img = NULL;
	data->params.img_we.img = NULL;
	data->params.img_ea.img = NULL;
	data->params.img_no.addr = NULL;
	data->params.img_so.addr = NULL;
	data->params.img_we.addr = NULL;
	data->params.img_ea.addr = NULL;
	data->params.ceiling = -1;
	data->params.floor = -1;
}

// mlx_get_data_addrはimg_ptr->dataを返すため、mlx_destroy_imageで解放される。
int	destroy_mlx_ptr(t_data *data)
{
	if (data->mlx_val.mlx_ptr && data->params.img_no.img)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_no.img);
	if (data->mlx_val.mlx_ptr && data->params.img_so.img)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_so.img);
	if (data->mlx_val.mlx_ptr && data->params.img_we.img)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_we.img);
	if (data->mlx_val.mlx_ptr && data->params.img_ea.img)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_ea.img);
	if (data->mlx_val.mlx_ptr && data->mlx_val.img_ptr)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->mlx_val.img_ptr);
	if (data->mlx_val.mlx_ptr && data->mlx_val.win_ptr)
		mlx_destroy_window(data->mlx_val.mlx_ptr, data->mlx_val.win_ptr);
	if (data->mlx_val.mlx_ptr)
	{
		mlx_destroy_display(data->mlx_val.mlx_ptr);
		free(data->mlx_val.mlx_ptr);
	}
	return (1);
}

void	deinit_exit(t_data *data, int exit_status)
{
	free_map(data->params.map, data->params.map_height);
	destroy_mlx_ptr(data);
	exit (exit_status);
}
