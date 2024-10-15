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

static void	update_coordinate(t_data *data, int key);

// ESC 65307
// <-  65361
// ->  65363
// w   119
// a   97
// s   115
// d   100
int	detect_keys(int key, t_data *data)
{
	if (key == 65307)
		detect_close(data);
	else if (key == 119 || key == 115 || key == 97 || key == 100)
		update_coordinate(data, key);
	else if (key == 65363 || key == 65361)
		update_angle(data, key);
	else
		return (0);
	// calculate_and_plot(data);
	// mlx_put_image_to_window(data->mlx_val.mlx_ptr, data->mlx_val.win_ptr, data->mlx_val.img_ptr, 0, 0);
	return (0);
}

// int	check_location(t_data *data, double x, double y)
// {
// 	if (data->params.map[(int)x][(int)y] == '0')
// 		return (0);
// }

// 向いているangleで、壁に突き当たるまでの距離計算
// 向いているangleと、1歩の移動距離から、
// cos, sinを用いて加算/減算するx, yを求める
// 移動予定座標までに壁がある場合、壁に接するまでx, yを変化
static void	update_coordinate(t_data *data, int key)
{
	double	dx;
	double	dy;
	double	slope;
	double	sign;
	int		angle;

	angle = data->player.angle;
	if (key == 100)
		angle += 90;
	else if (key == 97)
		angle -= 90;
	else if (key == 115)
		angle += 180;
	angle = reset_angle(angle);
	if ((270 < angle && angle < 360) || (0 < angle && angle < 90))
		sign = 1.0;
	else
		sign = -1.0;
	// 1. 移動する一次関数の傾きを求める(横方向の移動はangleが90度増減)
	// 1.1. 横方向への移動だった場合、angleを修正
	// 右移動: angle+90 左移動:angle-90
	// 修正後angleで傾きを求めて、移動方向によって値を増減
	// 2. 一次関数上で、移動方向に向けて増減
	// 3. 移動中、壁の領域に入ったら戻って壁に接する座標を取得
	dx = 10 * cos_degree(data->player.angle) - cos_degree(data->player.angle);
	dy = 10 * sin_degree(data->player.angle) - sin_degree(data->player.angle);
	// dxかdyが0なら分岐(slopeが発散する)
	slope = dy / dx;
	printf("angle %d, sign %f, slope %f \n", angle, sign, slope);
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
