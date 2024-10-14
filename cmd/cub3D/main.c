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

static void	set_hooks_and_loop(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (valid_argument(argc, argv))
		return (1);
	if (init_data(&data, argv[1]))
		return (1);
	if (parse_cub(&data, argv[1]))
		return (destroy_mlx_ptr(&data));
	// 確認用
	printf("map_w:%d map_h:%d\n", data.params.map_width, data.params.map_height);
	printf("floor: %x ceiling:%x\n", data.params.floor, data.params.ceiling);
	int i = -1;
	while (data.params.map[++i])
		printf("%d %s\n", i, data.params.map[i]);
	set_hooks_and_loop(&data);
	return (0);
}

// int	test_print(t_data *data)
// {
// 	printf("pos_x: %d, pos_y: %d\n", data->pos_x, data->pos_y);
// 	return (0);
// }

static void	set_hooks_and_loop(t_data *data)
{
	mlx_key_hook(data->mlx_val.win_ptr, detect_keys, data);
	mlx_hook(data->mlx_val.win_ptr, 17, 0, detect_close, data);
	// mlx_loop_hook(data->mlx_val.mlx_ptr, test_print, data);
	mlx_loop(data->mlx_val.mlx_ptr);
}
