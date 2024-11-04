/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coodinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:43:41 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 05:00:52 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_to_edge(t_dda *dda_ret, t_data *data, double mv_angle);

void	update_coordinate(t_data *data, int key)
{
	double		angle;
	t_dda		dda_ret;
	t_player	adjust_player;

	angle = data->player.angle;
	if (key == XK_d)
		angle += 90.0;
	else if (key == XK_a)
		angle -= 90.0;
	else if (key == XK_s)
		angle += 180.0;
	angle = regulate_angle(angle);
	adjust_player.pos_x = data->player.pos_x;
	adjust_player.pos_y = data->player.pos_y;
	adjust_player.angle = angle;
	dda_ret = dda(&adjust_player, data->params.map);
	set_player_to_edge(&dda_ret, data, angle);
}

static void	set_player_to_edge(t_dda *dda, t_data *d, double mv_angle)
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
