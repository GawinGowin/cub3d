/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyzer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:02:53 by saraki            #+#    #+#             */
/*   Updated: 2024/10/22 07:07:59 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double		get_distination_delta(double distination_element);

static t_side_dist	get_side_distination(
						t_player *player,
						double ray_distination[2],
						double delta_dist[2],
						int pos_index[2]);
static void			ray_cast(
						t_side_dist side_dist,
						int pos_index[2],
						char **map,
						t_dda *ret);
static void			get_distance_and_hitblock(
						int pos_index[2],
						double dist[2],
						t_dda *ret);

t_dda	dda(t_player *player, char **map)
{
	t_dda			ret;
	int				pos_index[2];
	t_side_dist		side_dist;

	ret.is_hit = 0;
	ret.ray_distination[0] = cos_degree(player->angle);
	ret.ray_distination[1] = sin_degree(player->angle);
	ret.delta_dist[0] = get_distination_delta(ret.ray_distination[0]);
	ret.delta_dist[1] = get_distination_delta(ret.ray_distination[1]);
	pos_index[0] = (int)player->pos_x;
	pos_index[1] = (int)player->pos_y;
	side_dist = get_side_distination(player, ret.ray_distination,
			ret.delta_dist, pos_index);
	ray_cast(side_dist, pos_index, map, &ret);
	return (ret);
}

static double	get_distination_delta(double distination_element)
{
	if ((distination_element == 0))
		return (1e30);
	return (fabs(1.0 / distination_element));
}

static t_side_dist	get_side_distination(
			t_player *player,
			double ray_distination[2],
			double delta_dist[2],
			int pos_index[2])
{
	t_side_dist	ret;

	if (ray_distination[0] < 0)
	{
		ret.step[0] = -1;
		ret.dist[0] = (player->pos_x - pos_index[0]) * delta_dist[0];
	}
	else
	{
		ret.step[0] = 1;
		ret.dist[0] = (pos_index[0] + 1.0 - player->pos_x) * delta_dist[0];
	}
	if (ray_distination[1] < 0)
	{
		ret.step[1] = -1;
		ret.dist[1] = (player->pos_y - pos_index[1]) * delta_dist[1];
	}
	else
	{
		ret.step[1] = 1;
		ret.dist[1] = (pos_index[1] + 1.0 - player->pos_y) * delta_dist[1];
	}
	return (ret);
}

static void	ray_cast(
				t_side_dist side_dist,
				int pos_index[2],
				char **map,
				t_dda *ret)
{
	double	distance[2];

	ret->is_hit = 0;
	distance[0] = side_dist.dist[0];
	distance[1] = side_dist.dist[1];
	while (ret->is_hit == 0)
	{
		if (ret->is_hit == 0 && distance[0] < distance[1])
		{
			distance[0] += ret->delta_dist[0];
			pos_index[0] += side_dist.step[0];
			ret->side = 0;
		}
		else if (ret->is_hit == 0 && distance[0] >= distance[1])
		{
			distance[1] += ret->delta_dist[1];
			pos_index[1] += side_dist.step[1];
			ret->side = 1;
		}
		if (pos_index[0] < 0 || pos_index[1] < 0)
			break ;
		else if (map[pos_index[0]][pos_index[1]] == WALL)
			ret->is_hit = 1;
	}
	get_distance_and_hitblock(pos_index, distance, ret);
}

static void	get_distance_and_hitblock(
				int pos_index[2],
				double dist[2],
				t_dda *ret)
{
	ret->hit_block[0] = 0;
	ret->hit_block[1] = 0;
	if (ret->is_hit == 1)
	{
		ret->hit_block[0] = pos_index[0];
		ret->hit_block[1] = pos_index[1];
	}
	if (ret->side == 0)
		ret->distance = dist[0];
	else
		ret->distance = dist[1];
}
