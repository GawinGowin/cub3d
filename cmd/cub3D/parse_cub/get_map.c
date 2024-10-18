/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:19:23 by saraki            #+#    #+#             */
/*   Updated: 2024/10/17 16:35:24 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(char **raw_map_lines, size_t width, size_t height)
{
	char	**map;
	size_t	i;
	size_t	org_len;

	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	map[height] = NULL;
	i = 0;
	while (i < height)
	{
		map[i] = ft_calloc(width + 1, sizeof(char));
		if (!map[i])
		{
			free_map(map, i);
			return (NULL);
		}
		org_len = ft_strlcpy(map[i], raw_map_lines[i], width);
		while (org_len < width)
			map[i][org_len++] = ' ';
		i++;
	}
	return (map);
}

void	get_mapsize(char **raw_map_lines, size_t *width, size_t *height)
{
	size_t	max_width;
	size_t	tmp_width;
	size_t	i;

	i = 0;
	max_width = 0;
	if (raw_map_lines == NULL || *raw_map_lines == NULL)
		return ;
	*height = get_height(raw_map_lines);
	while(raw_map_lines[i] != NULL)
	{
		tmp_width = ft_strlen(raw_map_lines[i]);
		if (tmp_width > max_width)
			max_width = tmp_width;
		i ++;
	}
	*width = max_width;
}

// static int	get_map(t_data *data, char **array, int i)
// {
// 	if (!array[i])
// 		return (printerror(ERR_FORMAT));
// 	while (array[i][0] == '\n')
// 		i++;
// 	get_size_of_map(data, array, i);
// 	if (copy_map(data, array, i))
// 		return (printerror(ERR_MALLOC));
// 	return (0);
// }

// static void	get_size_of_map(t_data *data, char **array, int i)
// {
// 	int	w;
// 	int	h;
// 	int	tmp_w;

// 	w = 0;
// 	h = 0;
// 	while (array[h + i] && array[h + i][0] != '\n' && array[h + i][0])
// 	{
// 		tmp_w = 0;
// 		tmp_w = strlen_ln(array[h + i]);
// 		if (tmp_w > w)
// 			w = tmp_w;
// 		h++;
// 	}
// 	data->params.map_height = h;
// 	data->params.map_width = w;
// }
