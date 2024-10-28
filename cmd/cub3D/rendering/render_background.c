/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:37:23 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 05:01:11 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_bg(t_mlx_val *mlx_val, int sky, int ground)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_color_to_img(mlx_val, x, y, sky);
			else
				put_color_to_img(mlx_val, x, y, ground);
			x++;
		}
		y++;
	}
}
