/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coodinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:43:41 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/26 23:51:11 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_to_edge(t_dda *dda_ret, t_data *data, int mv_angle);

void	update_coordinate(t_data *data, int key)
{
	int			angle;
	t_dda		dda_ret;
	t_player	adjust_player;

	angle = data->player.angle;
	if (key == KEY_D)
		angle += 90;
	else if (key == KEY_A)
		angle -= 90;
	else if (key == KEY_S)
		angle += 180;
	angle = regulate_angle(angle);
	adjust_player.pos_x = data->player.pos_x;
	adjust_player.pos_y = data->player.pos_y;
	adjust_player.angle = angle;
	dda_ret = dda(&adjust_player, data->params.map);
	if (dda_ret.is_hit)
		printf("hitblock: (%zu, %zu)/ distance: %f\n",
			dda_ret.hit_block[0], dda_ret.hit_block[1], dda_ret.distance);
	else
		printf("no hitblock\n");
	set_player_to_edge(&dda_ret, data, angle);
}

static void	set_player_to_edge(t_dda *dda, t_data *d, int mv_angle)
{
	double		next_distance;
	double		next[2];

	next[0] = STRIDE * cos_degree(mv_angle);
	next[1] = STRIDE * sin_degree(mv_angle);
	if (dda->side == 0)
		next_distance = dda->dist_option[0] - dda->delta_dist[0] - OFFSET;
	else
		next_distance = dda->dist_option[1] - dda->delta_dist[1] - OFFSET;
	if (next_distance > sqrt(next[0] * next[0] + next[1] * next[1]))
	{
		d->player.pos_x += next[0];
		d->player.pos_y += next[1];
	}
	else
	{
		d->player.pos_x += next_distance * cos_degree(mv_angle);
		d->player.pos_y += next_distance * sin_degree(mv_angle);
	}
	return ;
}
