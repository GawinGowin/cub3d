/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:42:03 by saraki            #+#    #+#             */
/*   Updated: 2024/10/28 04:10:27 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_image(t_mlx_val *mlx)
{
	void		*mlx_ptr;
	void		*img_ptr;

	mlx_ptr = mlx->mlx_ptr;
	img_ptr = mlx->img_ptr;
	mlx_clear_window(mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx_ptr, mlx->win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, img_ptr);
	img_ptr = NULL;
	mlx->img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
		return (1);
	return (0);
}

void	put_color_to_img(t_mlx_val *mlx_val, size_t x, size_t y, int color)
{
	unsigned int	index;
	unsigned int	*metrix;

	index = y * mlx_val->line_byte + x * (mlx_val->bpp / 8);
	metrix = (unsigned int *)mlx_val->addr;
	metrix[index] = color;
}
