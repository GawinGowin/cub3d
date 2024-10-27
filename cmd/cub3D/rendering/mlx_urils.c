/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_urils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:38:04 by saraki            #+#    #+#             */
/*   Updated: 2024/10/27 09:40:53 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx_ptr(t_data *data, char *name)
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

// mlx_get_data_addrはimg_ptr->dataを返すため、mlx_destroy_imageで解放される。
int	destroy_mlx_ptr(t_data *data)
{
	if (data->mlx_val.mlx_ptr && data->params.img_no)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_no);
	if (data->mlx_val.mlx_ptr && data->params.img_so)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_so);
	if (data->mlx_val.mlx_ptr && data->params.img_we)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_we);
	if (data->mlx_val.mlx_ptr && data->params.img_ea)
		mlx_destroy_image(data->mlx_val.mlx_ptr, data->params.img_ea);
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
