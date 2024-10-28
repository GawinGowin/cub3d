/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:27:49 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 15:42:01 by saraki           ###   ########.fr       */
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
	line_height = (int)(WIN_HEIGHT / dda->distance);
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

static void	rotate_player(t_player *adjusted_player, double x)
{
	double		dir[2];
	double		plane[2];
	double		plane_org[2];
	double		angle;
	double		camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	angle = (double) adjusted_player->angle;
	plane_org[0] = 0;
	plane_org[1] = tan(FOV / 2.0 * (PI / 180.0));
	dir[0] = cos_degree(angle);
	dir[1] = sin_degree(angle);
	plane[0] = plane_org[0] * dir[0] - plane_org[1] * dir[1];
	plane[1] = plane_org[0] * dir[1] + plane_org[1] * dir[0];
	dir[0] = dir[0] + plane[0] * camera_x;
	dir[1] = dir[1] + plane[1] * camera_x;
	angle = atan2(dir[1], dir[0]) * (180.0 / PI);
	adjusted_player->angle = regulate_angle(angle + adjusted_player->angle);
	return ;
}
