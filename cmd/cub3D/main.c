/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/12 07:12:14 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx_ptr(t_cub3d *data, char *name);
static void	init_param(t_cub3d *data);
static void	set_hooks_and_loop(t_cub3d *data);

int	main(int argc, char **argv)
{
	t_cub3d	data;

	if (valid_argument(argc, argv))
		return (1);
	if (init_mlx_ptr(&data, argv[1]))
		return (printerror(ERR_FAILED_INIT_MLX));
	data.cubfile_array = set_array_from_file(argv[1]);
	if (!data.cubfile_array)
		return (destroy_mlx_ptr(&data));
	// 確認用
	// sleep(3);
	// i = 0;
	// while (data.cubfile_array[i])
	// {
	// 	printf("> %s\n", data.cubfile_array[i]);
	// 	free(data.cubfile_array[i]);
	// 	i++;
	// }
	// destroy_mlx_ptr(&data);
	// i = -1;
	// while (data.cubfile_array[++i])
	// 	free(data.cubfile_array[i]);
	// free(data.cubfile_array);
	set_hooks_and_loop(&data);
	return (0);
}

static void	init_param(t_cub3d *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->angle = 0;
	data->bpp = 0;
	data->line_byte = 0;
	data->endian = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
}

static int	init_mlx_ptr(t_cub3d *data, char *name)
{
	init_param(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name);
	if (!data->win_ptr)
		return (destroy_mlx_ptr(data));
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img_ptr)
		return (destroy_mlx_ptr(data));
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_byte, \
		&data->endian);
	if (!data->addr)
		return (destroy_mlx_ptr(data));
	return (0);
}

// int	test_print(t_cub3d *data)
// {
// 	printf("pos_x: %d, pos_y: %d\n", data->pos_x, data->pos_y);
// 	return (0);
// }

static	void	set_hooks_and_loop(t_cub3d *data)
{
	mlx_key_hook(data->win_ptr, detect_keys, data);
	mlx_hook(data->win_ptr, 17, 0, detect_close, data);
	// mlx_loop_hook(data->mlx_ptr, test_print, data);
	mlx_loop(data->mlx_ptr);
}
