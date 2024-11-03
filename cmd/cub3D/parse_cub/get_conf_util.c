/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:52:48 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/03 10:13:57 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_id_direction(char *id)
{
	if (ft_strcmp(id, "NO") == 0 || ft_strcmp(id, "SO") == 0
		|| ft_strcmp(id, "WE") == 0 || ft_strcmp(id, "EA") == 0)
		return (1);
	return (0);
}

int	is_id_color(char *id)
{
	if (ft_strcmp(id, "F") == 0 || ft_strcmp(id, "C") == 0)
		return (1);
	return (0);
}

int	is_id_in_line(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, "SO", 2) == 0
		|| ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, "EA", 2) == 0
		|| ft_strncmp(str, "F", 1) == 0 || ft_strncmp(str, "C", 1) == 0)
		return (1);
	return (0);
}

int	is_all_flags(int flags)
{
	int	require;

	require = FLAG_NO | FLAG_SO | FLAG_WE | FLAG_EA | FLAG_F | FLAG_C;
	if ((flags & require) == require)
		return (1);
	return (0);
}

void	set_img_stract(t_texture *img, void *img_ptr, int width, int height)
{
	img->img = img_ptr;
	img->width = width;
	img->height = height;
	return ;
}
