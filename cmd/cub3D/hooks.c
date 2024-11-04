/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 04:11:42 by saraki            #+#    #+#             */
/*   Updated: 2024/11/04 04:54:23 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_data *data);
static int	key_release_handler(int key, t_data *data);
static int	detect_close(t_data *data);

void	load_hooks_and_loop(t_data *data)
{
	mlx_hook(data->mlx_val.win_ptr,
		KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->mlx_val.win_ptr,
		KeyRelease, KeyReleaseMask, key_release_handler, data);
	mlx_hook(data->mlx_val.win_ptr,
		DestroyNotify, NoEventMask, detect_close, data);
	mlx_loop_hook(data->mlx_val.mlx_ptr, update_screen, data);
	mlx_loop(data->mlx_val.mlx_ptr);
}

static int	key_press_handler(int key, t_data *data)
{
	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
		update_coordinate(data, key);
	else if (key == XK_Left || key == XK_Right)
		update_angle(data, key);
	data->is_moving = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		detect_close(data);
	data->is_moving = 0;
	return (0);
}

static int	detect_close(t_data *data)
{
	deinit_exit(data, 0);
	return (0);
}
