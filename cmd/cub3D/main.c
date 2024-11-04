/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 19:28:55 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initial_renderring(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (valid_argument(argc, argv))
		return (1);
	if (init_data(&data, argv[1]))
		return (1);
	if (parse_cub(&data, argv[1]))
		return (destroy_mlx_ptr(&data));
	if (!is_validate(&data))
	{
		free_2d_array_of_char(data.params.map);
		return (destroy_mlx_ptr(&data));
	}
	output_map_info(&data);
	initial_renderring(&data);
	load_hooks_and_loop(&data);
	return (0);
}

static void	initial_renderring(t_data *data)
{
	data->is_moving = 1;
	update_screen(data);
	data->is_moving = 0;
}
