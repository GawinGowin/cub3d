/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:06:16 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/27 01:24:53 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_color_to_img(t_data *data, int x, int y, int color)
{
	unsigned int	i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	i = y * data->mlx_val.line_byte + x * (data->mlx_val.bpp / 8);
	data->mlx_val.addr[i] = color;
	data->mlx_val.addr[i + 1] = color >> 8;
	data->mlx_val.addr[i + 2] = color >> 16;
}
