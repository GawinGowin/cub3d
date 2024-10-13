/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_and_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 09:55:33 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-11 09:55:33 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map(t_data *data, char **array, int i);
static void	get_size_of_map(t_data *data, char **array, int i);
static int	copy_map(t_data *data, char **array, int i);

int	get_conf_and_map(t_data *data, char **array)
{
	int		i;

	i = 0;
	i = get_conf(data, array);
	if (i < 0)
		return (1);
	if (get_map(data, array, i + 1))
		return (1);
	return (0);
}

int	splited_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int	get_map(t_data *data, char **array, int i)
{
	if (!array[i])
		return (1);
	while (array[i][0] == '\n')
		i++;
	get_size_of_map(data, array, i);
	if (copy_map(data, array, i))
		return (1);
	return (0);
}

static int	copy_map(t_data *data, char **array, int i)
{
	int	j;
	int	size;

	size = (data->params.map_height + 1) * sizeof(char *);
	data->params.map = (char **)malloc(size);
	if (!data->params.map)
		return (1);
	j = -1;
	while (++j < data->params.map_height)
	{
		data->params.map[j] = ft_strtrim(array[j + i], "\n");
		if (!data->params.map[j])
		{
			while (--j >= 0)
				free(data->params.map[j]);
			free(data->params.map);
			return (1);
		}
	}
	return (0);
}

static void	get_size_of_map(t_data *data, char **array, int i)
{
	int	w;
	int	h;
	int	tmp_w;

	w = 0;
	h = 0;
	while (array[h + i] && array[h + i][0] != '\n' && array[h + i][0])
	{
		tmp_w = 0;
		tmp_w = strlen_ln(array[h + i]);
		if (tmp_w > w)
			w = tmp_w;
		h++;
	}
	data->params.map_height = h;
	data->params.map_width = w;
}
