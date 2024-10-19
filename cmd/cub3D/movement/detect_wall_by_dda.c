/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall_by_dda.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 11:29:15 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-15 11:29:15 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (fabs(1 / ray_dir));
}

typedef struct s_dda
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
}	t_dda;

typedef struct s_wall
{
	double	x;
	double	y;
	double	dist;
}	t_wall;

static void	set_step_side_dist(t_dda *dda, t_data *data)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (data->player.pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (1.0 - data->player.pos_x + dda->map_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (data->player.pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (1.0 - data->player.pos_y + dda->map_y) * dda->delta_dist_y;
	}
}

static void	set_dda_param(t_dda *dda, t_data *data, int angle)
{
	// レイのx, yの方向ベクトル
	dda->ray_dir_x = cos_degree(angle);
	dda->ray_dir_y = sin_degree(angle);
	// 現在地がmap上のどの座標(整数値)にいるか
	dda->map_x = floor(data->player.pos_x);
	dda->map_y = floor(data->player.pos_y);
	// xやyが1ユニット増加したときのレイの長さ
	dda->delta_dist_x = get_delta_dist(dda->ray_dir_x);
	dda->delta_dist_y = get_delta_dist(dda->ray_dir_y);
	set_step_side_dist(dda, data);
}

t_wall	detect_wall_by_dda(t_data *data, double angle)
{
	t_wall	wall;
	t_dda	dda;
	int	side = 0; // side=0: EWに衝突 side=1: NSに衝突
	double	ray_dist = 0;

	set_dda_param(&dda, data, angle);
	wall.x = 0.0;
	wall.y = 0.0;
	wall.dist = 0.0;
	while (1)
	{
		if (dda.side_dist_x < dda.side_dist_y)
		{
			dda.side_dist_x += dda.delta_dist_x;
			dda.map_x += dda.step_x;
			side = 0;
		}
		else
		{
			dda.side_dist_y += dda.delta_dist_y;
			dda.map_y += dda.step_y;
			side = 1;
		}
		if (data->params.map[dda.map_x][dda.map_y] == WALL)
			break ;
	}
	if (side == 0)
		ray_dist = dda.side_dist_x - dda.delta_dist_x;
	else
		ray_dist = dda.side_dist_y - dda.delta_dist_y;
	wall.x = data->player.pos_x + ray_dist * dda.ray_dir_x;
	wall.y = data->player.pos_y + ray_dist * dda.ray_dir_y;
	wall.dist = ray_dist;
	return (wall);
}
