/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:27:49 by saraki            #+#    #+#             */
/*   Updated: 2024/11/03 17:15:21 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	rotate_player(t_player *adjusted_player, double x);
static int		render_a_line(t_data *data,	size_t x,
					t_dda *dda, int line_height);

int	render_walls(t_data *data, t_player *player)
{
	size_t		x;
	t_player	adjusted_player;
	t_dda		ret;
	int			line_height;
	double		azimuth;

	x = 0;
	while (x < WIN_WIDTH)
	{
		adjusted_player = *player;
		azimuth = rotate_player(&adjusted_player, (double) x);
		ret = dda(&adjusted_player, data->params.map);
		line_height = (int)(WIN_HEIGHT / ret.distance / cos_degree(azimuth));
		if (render_a_line(data, x, &ret, line_height))
		{
			
			return (1);
		}
		x ++;
	}
	return (0);
}

static int	render_a_line(t_data *data,	size_t x, t_dda *dda, int line_height)
{
	int		y;
	int		color;
	int		range[2];
	int		original_range[2];

	original_range[0] = -line_height / 2 + WIN_HEIGHT / 2;
	original_range[1] = line_height / 2 + WIN_HEIGHT / 2;
	range[0] = original_range[0];
	range[1] = original_range[1];
	if (range[0] < 0)
		range[0] = 0;
	if (range[1] >= WIN_HEIGHT)
		range[1] = WIN_HEIGHT - 1;
	y = range[0];
	while (y <= range[1])
	{
		color = pick_texture_color(data, dda,
				((double)y - (double)original_range[0])
				/ ((double)original_range[1] - (double)original_range[0]));
		if (color == -1)
			return (-1);
		put_color_to_img(&(data->mlx_val), x, y, color);
		y++;
	}
	return (0);
}

static double	rotate_player(t_player *adjusted_player, double x)
{
	double		dir[2];
	double		plane[2];
	double		plane_org[2];
	double		angle;
	double		camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	plane_org[0] = 0;
	plane_org[1] = tan(FOV / 2.0 * (PI / 180.0));
	dir[0] = cos_degree(adjusted_player->angle);
	dir[1] = sin_degree(adjusted_player->angle);
	plane[0] = plane_org[0] * dir[0] - plane_org[1] * dir[1];
	plane[1] = plane_org[0] * dir[1] + plane_org[1] * dir[0];
	dir[0] = dir[0] + plane[0] * camera_x;
	dir[1] = dir[1] + plane[1] * camera_x;
	angle = adjusted_player->angle;
	adjusted_player->angle = atan2(dir[1], dir[0]) * (180.0 / PI);
	return (angle - adjusted_player->angle);
}
