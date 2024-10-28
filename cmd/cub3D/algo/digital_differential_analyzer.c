/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyzer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:02:53 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 16:45:44 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double		get_distination_delta(double distination_element);
static t_side_dist	get_side_distination(
						t_player *org,
						double _ray_distination[2],
						double delta_dist[2]);
static void			ray_cast(
						int pos_index[2],
						char **map,
						t_dda *ret);
static void			get_distance_and_hitblock(
						int pos_index[2],
						t_dda *ret);

t_dda	dda(t_player *org, char **map)
{
	t_dda			ret;
	int				pos_index[2];

	ret.is_hit = 0;
	ret._ray_distination[0] = cos_degree(org->angle);
	ret._ray_distination[1] = sin_degree(org->angle);
	ret.delta_dist[0] = get_distination_delta(ret._ray_distination[0]);
	ret.delta_dist[1] = get_distination_delta(ret._ray_distination[1]);
	pos_index[0] = (int)org->pos_x;
	pos_index[1] = (int)org->pos_y;
	ret._side_dist = get_side_distination(org,
			ret._ray_distination, ret.delta_dist);
	ray_cast(pos_index, map, &ret);
	return (ret);
}

static double	get_distination_delta(double distination_element)
{
	if (distination_element == 0)
		return (1e30);
	return (fabs(1.0 / distination_element));
}

static t_side_dist	get_side_distination(
			t_player *org,
			double _ray_distination[2],
			double delta_dist[2])
{
	t_side_dist	ret;

	if (_ray_distination[0] < 0)
	{
		ret.step[0] = -1;
		ret.dist[0] = (org->pos_x - (int)org->pos_x) * delta_dist[0];
	}
	else
	{
		ret.step[0] = 1;
		ret.dist[0] = ((int)org->pos_x + 1.0 - org->pos_x) * delta_dist[0];
	}
	if (_ray_distination[1] < 0)
	{
		ret.step[1] = -1;
		ret.dist[1] = (org->pos_y - (int)org->pos_y) * delta_dist[1];
	}
	else
	{
		ret.step[1] = 1;
		ret.dist[1] = ((int)org->pos_y + 1.0 - org->pos_y) * delta_dist[1];
	}
	return (ret);
}

static void	ray_cast(
				int pos_index[2],
				char **map,
				t_dda *ret)
{
	ret->is_hit = 0;
	ret->dist_option[0] = ret->_side_dist.dist[0];
	ret->dist_option[1] = ret->_side_dist.dist[1];
	while (ret->is_hit == 0)
	{
		if (ret->is_hit == 0 && ret->dist_option[0] < ret->dist_option[1])
		{
			ret->dist_option[0] += ret->delta_dist[0];
			pos_index[0] += ret->_side_dist.step[0];
			ret->side = 0;
		}
		else if (ret->is_hit == 0 && ret->dist_option[0] >= ret->dist_option[1])
		{
			ret->dist_option[1] += ret->delta_dist[1];
			pos_index[1] += ret->_side_dist.step[1];
			ret->side = 1;
		}
		if (pos_index[0] < 0 || pos_index[1] < 0)
			break ;
		else if (map[pos_index[1]][pos_index[0]] == WALL)
			ret->is_hit = 1;
	}
	get_distance_and_hitblock(pos_index, ret);
}

static void	get_distance_and_hitblock(
				int pos_index[2],
				t_dda *ret)
{
	ret->hit_block[0] = 0;
	ret->hit_block[1] = 0;
	if (ret->is_hit == 1)
	{
		ret->hit_block[0] = (size_t) pos_index[0];
		ret->hit_block[1] = (size_t) pos_index[1];
	}
	if (ret->side == 0)
		ret->distance = ret->dist_option[0] - ret->delta_dist[0];
	else if (ret->side == 1)
		ret->distance = ret->dist_option[1] - ret->delta_dist[1];
	else
		ret->distance = 0;
}
