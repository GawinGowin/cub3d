/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 04:16:47 by saraki           ###   ########.fr       */
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
	// 確認用
	printf("map_w:%zu map_h:%zu\n", data.params.map_width, data.params.map_height);
	printf("floor: %x ceiling:%x\n", data.params.floor, data.params.ceiling);
	int i = -1;
	while (data.params.map[++i])
		printf("%d %s\n", i, data.params.map[i]);
	printf("%d %s\n", i, data.params.map[i]);
	update_screen(&data);
	load_hooks_and_loop(&data);
	return (0);
}
