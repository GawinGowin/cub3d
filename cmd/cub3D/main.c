/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/27 01:03:29 by syamasaw         ###   ########.fr       */
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
	if (parse_cub(&data, argv[1]) || !is_validate(&data))
		return (destroy_mlx_ptr(&data));
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
