/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_texture_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:37:57 by saraki            #+#    #+#             */
/*   Updated: 2024/11/03 03:51:40 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	identify_texture(t_param_cub *params,
						t_dda *dda, int *line_byte, int *bpp);

int	pick_texture_color(t_data *data, t_dda *dda, double texture_y)
{
	t_texture		texture;
	int				line_byte;
	int				color;
	double			hit_x_of_texture;
	int				bpp;

	line_byte = 0;
	bpp = 0;
	texture = identify_texture(&(data->params), dda, &line_byte, &bpp);
	if (texture.img == NULL || texture.addr == NULL)
		return (-1);
	hit_x_of_texture = dda->distance
		* cos(atan2(dda->ray_distination[1], dda->ray_distination[0]))
		+ data->player.pos_x
		- (double) dda->hit_block[0];
	color = *(unsigned int *)(texture.addr
			+ ((int)(texture_y * texture.height) * line_byte
			+ (int)(hit_x_of_texture * texture.width * bpp / 8)));
	return (color);
}

static t_texture	identify_texture(t_param_cub *params,
						t_dda *dda, int *line_byte, int *bpp)
{
	t_texture	texture;
	int			endian;

	if (dda->side == 1 && dda->ray_distination[0] > 0)
		texture = params->img_so;
	else if (dda->side == 1 && dda->ray_distination[0] <= 0)
		texture = params->img_no;
	else if (dda->side == 0 && dda->ray_distination[1] > 0)
		texture = params->img_ea;
	else
		texture = params->img_we;
	if (texture.img == NULL)
		return ((t_texture){NULL, NULL, 0, 0});
	if (texture.addr == NULL)
		texture.addr = mlx_get_data_addr(texture.img, bpp, line_byte, &endian);
	if (texture.addr == NULL)
		return ((t_texture){NULL, NULL, 0, 0});
	return (texture);
}
