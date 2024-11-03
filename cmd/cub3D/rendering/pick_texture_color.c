/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_texture_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:37:57 by saraki            #+#    #+#             */
/*   Updated: 2024/11/03 00:27:52 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		*identify_texture_array(t_param_cub *params,
					t_dda *dda, int *line_byte);

int	pick_texture_color(t_data *data, t_dda *dda, double texture_y)
{
	void			*metrix;
	int				line_byte;
	int				color;
	double			hit_x_of_texture;
	double			rad;

	line_byte = 0;
	metrix = identify_texture_array(&(data->params), dda, &line_byte);
	if (!metrix)
		return (-1);
	rad = atan2(dda->ray_distination[1], dda->ray_distination[0]);
	double cosine = dda->distance * cos(rad);
	(void) cosine;
	hit_x_of_texture = dda->distance * cos(rad) + data->player.pos_x
						- (double) dda->hit_block[0];
	color = *(unsigned int *)(metrix + (int)(texture_y * XPM_SIZE) * line_byte
			 + (int)(hit_x_of_texture * XPM_SIZE));
	return (color);
}

static void	*identify_texture_array(t_param_cub *params, t_dda *dda, int *line_byte)
{
	void	*image_pt;
	int		bpp;
	int		endian;

	if (dda->side == 1 && dda->ray_distination[0] > 0)
			image_pt = params->img_so;
	else if (dda->side == 1 && dda->ray_distination[0] <= 0)
			image_pt = params->img_no;
	else if (dda->side == 0 && dda->ray_distination[1] > 0)
			image_pt = params->img_ea;
	else
			image_pt = params->img_we;
	return (mlx_get_data_addr(image_pt, &bpp, line_byte, &endian));
}
