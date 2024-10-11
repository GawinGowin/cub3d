/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 02:50:34 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static int	init_mlx_ptr(t_cub3d *data, char *name);
static void	destroy_mlx_ptr(t_cub3d *data);

int	main(int argc, char **argv)
{
	t_cub3d	data;
	int		i;

	if (valid_argument(argc, argv))
		return (1);
	init_mlx_ptr(&data, argv[1]);
	data.cubfile_array = set_array_from_file(argv[1]);
	if (!data.cubfile_array)
		return (1);
	// 確認用
	while (data.cubfile_array[i])
	{
		printf("> %s\n", data.cubfile_array[i]);
		free(data.cubfile_array[i]);
		i++;
	}
	destroy_mlx_ptr(&data);
	free(data.cubfile_array);
	return (0);
}

static int	init_mlx_ptr(t_cub3d *data, char *name)
{
	data->bpp = 0;
	data->line_byte = 0;
	data->endian = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_byte, \
		&data->endian);
	return (0);
}

static void	destroy_mlx_ptr(t_cub3d *data)
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
}

