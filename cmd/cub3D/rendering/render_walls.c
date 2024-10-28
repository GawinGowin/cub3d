/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:27:49 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 12:27:27 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_player *player, double x);
static void	render_a_line(t_mlx_val *mlx,
				t_param_cub *params, size_t x, t_dda *dda);

void	render_walls(t_mlx_val *mlx, t_player *player, t_param_cub *params)
{
	size_t		x;
	t_player	adjusted_player;
	t_dda		dda_ret;

	x = 0;
	while (x < WIN_WIDTH)
	{
		adjusted_player = *player;
		rotate_player(&adjusted_player, (double) x);
		dda_ret = dda(&adjusted_player, params->map);
		render_a_line(mlx, params, x, &dda_ret);
		x ++;
	}
}

static void	render_a_line(t_mlx_val *mlx,
				t_param_cub *params, size_t x, t_dda *dda)
{
	int		i;
	int		line_height;
	int		temp_color;
	int		start;
	int		end;

	(void) params;
	temp_color = (0 << 16) | (128 << 8) | 0;
	line_height = abs((int) (WIN_HEIGHT / dda->distance / cos_degree(180 - (2 * x / (double) FOV - (FOV / 2)))));
	start = -line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WIN_HEIGHT / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	i = start;
	while (i <= end)
	{
		if (dda->side)
			put_color_to_img(mlx, x, i, temp_color);
		else
			put_color_to_img(mlx, x, i, temp_color / 2);
		i++;
	}
}

static void	rotate_player(t_player *player, double x)
{
	double		norm;

	norm = 2 * x / (double) WIN_WIDTH - (FOV / 2.0);
	player->angle = regulate_angle(player->angle + norm);
	return ;
}
