/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 06:17:26 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/27 01:03:06 by syamasaw         ###   ########.fr       */
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
	return (0);
}

int	detect_close(t_data *data)
{
	free_2d_array_of_char(data->params.map);
	destroy_mlx_ptr(data);
	exit (0);
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
