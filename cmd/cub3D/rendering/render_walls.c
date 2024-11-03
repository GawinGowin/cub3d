/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:27:49 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 17:59:39 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	rotate_player(t_player *adjusted_player, double x);
static int		render_a_line(t_data *data,
					size_t x, t_dda *dda, double azimuth_angle);

void	render_walls(t_data *data, t_player *player)
{
	size_t		x;
	t_player	adjusted_player;
	t_dda		dda_ret;
	double		azimuth_angle;

	x = 0;
	while (x < WIN_WIDTH)
	{
		adjusted_player = *player;
		azimuth_angle = rotate_player(&adjusted_player, (double) x);
		dda_ret = dda(&adjusted_player, data->params.map);
		if (render_a_line(data, x, &dda_ret, azimuth_angle))
			return ;
		x ++;
	}
	return ;
}

static int	render_a_line(t_data *data,
				size_t x, t_dda *dda, double azimuth_angle)
{
	size_t	y;
	int		line_height;
	int		color;
	int		start;
	size_t	end;

	line_height = (int)(WIN_HEIGHT / dda->distance / cos_degree(azimuth_angle));
	start = -line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WIN_HEIGHT / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	y = (size_t) start;
	while (y <= end)
	{
		if (dda->side)
			put_color_to_img(mlx, x, i, temp_color);
		else
			put_color_to_img(mlx, x, i, temp_color / 2);
		i++;
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
