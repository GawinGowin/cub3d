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

// ESC 65307
// <-  65301
// ->  65363
// w   119
// a   97
// s   115
// d   100
int	detect_keys(int key, t_cub3d *data)
{
	// 移動/視点の処理は適当
	// オーバーフローや視点が1周したときの角度とかも考慮する
	if (key == 65307)
		detect_close(data);
	else if (key == 119)
		data->pos_y++;
	else if (key == 115)
		data->pos_y--;
	else if (key == 97)
		data->pos_x--;
	else if (key == 100)
		data->pos_x++;
	else if (key == 65363)
		data->angle++;
	else if (key == 65301)
		data->angle--;
	else
		return (0);
	// calculate_and_plot(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	detect_close(t_cub3d *data)
{
	int	i;

	i = -1;
	while (data->cubfile_array[++i])
		free(data->cubfile_array[i]);
	free(data->cubfile_array);
	destroy_mlx_ptr(data);
	exit (0);
	return (0);
}

// mlx_get_data_addrはimg_ptr->dataを返すため、mlx_destroy_imageで解放される。
int	destroy_mlx_ptr(t_cub3d *data)
{
	if (data->mlx_ptr && data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (1);
}
