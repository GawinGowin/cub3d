/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_texture_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:37:57 by saraki            #+#    #+#             */
/*   Updated: 2024/11/06 02:44:12 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	identify_texture(t_param_cub *params,
						t_dda *dda, int *line_byte, int *bpp);
static int			pick_a_color_from_metrix(t_texture *texture,
						size_t x, size_t y, int line_byte);
static double		adjust_texture_x_coodinate(t_dda *dda, t_player *player);

/**
 * @brief Picks the color from the texture based on the given parameters.
 *
 * This function calculates the color from the texture at the specified
 * coordinates and returns it. It uses the data from the `t_data` and `t_dda`
 * structures to determine the exact color to pick.
 *
 * @param data Pointer to the main data structure containing texture information.
 * @param dda Pointer to the DDA (Digital Differential Analyzer) structure used
 *            for raycasting calculations.
 * @param texture_y The y-coordinate on the texture from which to pick the color.
 * @note the value range:
 * 		- `texture_y` : 0 <= texture_y <= 1
 * 		- `texture_x` : 0 <= texture_x <= 1
 * @return The color value picked from the texture.
 */
int	pick_texture_color(t_data *data, t_dda *dda, double texture_y)
{
	t_texture		texture;
	int				line_byte;
	int				color;
	double			texture_x;
	int				bpp;

	line_byte = 0;
	bpp = 0;
	texture = identify_texture(&(data->params), dda, &line_byte, &bpp);
	if (texture.img == NULL || texture.addr == NULL)
		return (-1);
	texture_x = adjust_texture_x_coodinate(dda, &(data->player));
	color = pick_a_color_from_metrix(&texture,
			(int)(texture_x * (double) texture.width),
			(int)(texture_y * (double) texture.height), line_byte);
	return (color);
}

static double	adjust_texture_x_coodinate(t_dda *dda, t_player *player)
{
	double	texture_x;
	double	angle[2];
	double	hit_block_x;
	double	hit_block_y;

	angle[1] = atan2(dda->ray_distination[1], dda->ray_distination[0]);
	angle[0] = atan2(dda->ray_distination[0], dda->ray_distination[1]);
	hit_block_x = (double) dda->hit_block[0];
	hit_block_y = (double) dda->hit_block[1];
	if (dda->side == 1 && dda->ray_distination[1] >= 0)
		texture_x = (hit_block_x + 1) - (dda->distance * cos(angle[1])
				+ player->pos_x);
	else if (dda->side == 1 && dda->ray_distination[1] < 0)
		texture_x = dda->distance * cos(angle[1])
			+ player->pos_x - hit_block_x;
	else if (dda->side == 0 && dda->ray_distination[0] >= 0)
		texture_x = dda->distance * cos(angle[0])
			+ player->pos_y - hit_block_y;
	else
		texture_x = (hit_block_y + 1) - (dda->distance * cos(angle[0])
				+ player->pos_y);
	return (texture_x);
}

static int	pick_a_color_from_metrix(t_texture *texture,
				size_t x, size_t y, int line_byte)
{
	int				color;
	unsigned int	*addr;
	int				y_lines_offset;

	addr = (unsigned int *) texture->addr;
	if (y >= (size_t) texture->height)
		y = texture->height - 1;
	if (x >= (size_t) texture->width)
		x = texture->width - 1;
	y_lines_offset = y * (line_byte) / 4;
	color = addr[x + y_lines_offset];
	return (color);
}

static t_texture	identify_texture(t_param_cub *params,
						t_dda *dda, int *line_byte, int *bpp)
{
	t_texture	texture;
	int			endian;

	if (dda->side == 1 && dda->ray_distination[1] >= 0)
		texture = params->img_so;
	else if (dda->side == 1 && dda->ray_distination[1] < 0)
		texture = params->img_no;
	else if (dda->side == 0 && dda->ray_distination[0] >= 0)
		texture = params->img_ea;
	else if (dda->side == 0 && dda->ray_distination[0] < 0)
		texture = params->img_we;
	if (texture.img == NULL)
		return ((t_texture){NULL, NULL, 0, 0});
	if (texture.addr == NULL)
		texture.addr = mlx_get_data_addr(texture.img, bpp, line_byte, &endian);
	if (texture.addr == NULL)
		return ((t_texture){NULL, NULL, 0, 0});
	return (texture);
}
