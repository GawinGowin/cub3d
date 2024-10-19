/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:39:33 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/19 22:41:05 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb(char **array);
static int	is_str_digit(char *str);

int	color_str_to_int(char *str)
{
	char	**tmp;
	int		ret;

	tmp = ft_split(str, ',');
	if (!tmp)
		return (-1);
	if (splited_length(tmp) != 3)
	{
		free_2d_array_of_char(tmp);
		return (-1);
	}
	ret = validate_rgb(tmp);
	free_2d_array_of_char(tmp);
	return (ret);
}

static int	validate_rgb(char **array)
{
	int	i;
	int	rgb[3];
	int	ret;

	i = -1;
	ret = 0;
	while (++i < 3 && array[i])
	{
		if (strlen_ln(array[i]) > 3 || !is_str_digit(array[i]))
			return (-1);
		rgb[i] = ft_atoi(array[i]);
		if (rgb[i] < 0 || 255 < rgb[i])
			return (-1);
	}
	ret = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (ret);
}

static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	strlen_ln(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
