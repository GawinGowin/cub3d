/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:42:03 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 05:49:21 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_image(t_mlx_val *mlx)
{
	void		*mlx_ptr;

	mlx_ptr = mlx->mlx_ptr;
	mlx_put_image_to_window(mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = NULL;
	mlx->img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
		return (1);
	return (0);
}

void	put_color_to_img(t_mlx_val *mlx_val, size_t x, size_t y, int color)
{
	unsigned int	index;
	int				bpp;
	int				line_byte;
	int				endian;
	void			*metrix;

	metrix = mlx_get_data_addr(mlx_val->img_ptr, &bpp, &line_byte, &endian);
	index = y * line_byte + x * (mlx_val->bpp / 8);
	*(unsigned int *)(metrix + index) = color;
}
