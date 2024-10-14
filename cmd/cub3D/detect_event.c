/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 06:17:26 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-11 06:17:26 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_angle(t_data *data, int key);

// ESC 65307
// <-  65361
// ->  65363
// w   119
// a   97
// s   115
// d   100
int	detect_keys(int key, t_data *data)
{
	// 移動/視点の処理は適当
	// オーバーフローや視点が1周したときの角度とかも考慮する
	if (key == 65307)
		detect_close(data);
	else if (key == 119)
		data->player.pos_y++;
	else if (key == 115)
		data->player.pos_y--;
	else if (key == 97)
		data->player.pos_x--;
	else if (key == 100)
		data->player.pos_x++;
	else if (key == 65363 || key == 65361)
		update_angle(data, key);
	else
		return (0);
	// calculate_and_plot(data);
	// mlx_put_image_to_window(data->mlx_val.mlx_ptr, data->mlx_val.win_ptr, data->mlx_val.img_ptr, 0, 0);
	return (0);
}

static void	update_angle(t_data *data, int key)
{
	int	now;

	now = data->player.angle;
	if (key == 65361)
		now += 10;
	else if (key == 65363)
		now -= 10;
	if (now < 0)
		now = 360 + now;
	else if (now >= 360)
		now = now - 360;
	data->player.angle = now;
	printf("angle: %d\n", data->player.angle);
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
