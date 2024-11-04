/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 04:11:42 by saraki            #+#    #+#             */
/*   Updated: 2024/11/04 04:24:16 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	test_print(t_data *data)
{
	printf("pos_x: %d, pos_y: %d\n", data->pos_x, data->pos_y);
	return (0);
}

static int	key_press_handler(t_data *data)
{
	printf("key pressed\n");
	return (0);
}

static int	key_release_handler(t_data *data)
{
	printf("key released\n");
	return (0);
}

void	load_hooks_and_loop(t_data *data)
{
	// mlx_key_hook(data->mlx_val.win_ptr, detect_keys, data);
	mlx_hook(data->mlx_val.win_ptr, KeyPress, KeyPressMask,  key_press_handler, data);
	mlx_hook(data->mlx_val.win_ptr, KeyRelease, KeyReleaseMask, key_release_handler, data);
	mlx_hook(data->mlx_val.win_ptr, DestroyNotify, NoEventMask, detect_close, data);
	mlx_loop_hook(data->mlx_val.mlx_ptr, update_screen, data);
	mlx_loop(data->mlx_val.mlx_ptr);
}

