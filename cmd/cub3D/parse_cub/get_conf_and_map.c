/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_and_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:33 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 10:54:37 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		is_only_contains_one_map(char **raw_lines);
static size_t	get_lines_cnt(char **lines);
static char		**drop_vacant_element_and_dup(char **line);

int	get_conf_and_map(t_data *data, char **raw_lines)
{
	char	**formed_lines;

	formed_lines = drop_vacant_element_and_dup(raw_lines);
	if (!formed_lines)
		return (printerror(ERR_MALLOC));
	if (get_conf(data, formed_lines))
	{
		free_map(formed_lines, get_lines_cnt(formed_lines));
		return (printerror(ERR_FORMAT));
	}
	get_mapsize(formed_lines + 6,
		&(data->params.map_width), &(data->params.map_height));
	if (!is_only_contains_one_map(raw_lines))
	{
		free_map(formed_lines, get_lines_cnt(formed_lines));
		return (printerror(ERR_FORMAT));
	}
	data->params.map = get_map(formed_lines + 6, data->params.map_width,
			data->params.map_height);
	free_map(formed_lines, get_lines_cnt(formed_lines));
	if (data->params.map == NULL)
		return (printerror(ERR_MALLOC));
	if (get_player(data))
		return (printerror(ERR_FORMAT));
	return (0);
}

static char	**drop_vacant_element_and_dup(char **lines)
{
	size_t	i;
	char	**formed_lines;

	if (lines == NULL || *lines == NULL)
		return (NULL);
	formed_lines = (char **)ft_calloc(sizeof(char *),
			(get_lines_cnt(lines) + 1));
	if (formed_lines == NULL)
		return (NULL);
	i = 0;
	while (*lines != NULL)
	{
		if (ft_strcmp(*lines, "\0") != 0)
		{
			formed_lines[i] = ft_strdup(*lines);
			if (!formed_lines[i])
			{
				free_map(formed_lines, i);
				return (NULL);
			}
			i ++;
		}
		lines ++;
	}
	return (formed_lines);
}

static size_t	get_lines_cnt(char **lines)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (!lines)
		return (0);
	while (lines[i])
	{
		if (ft_strcmp(lines[i++], "\0") == 0)
			continue ;
		len++;
	}
	return (len);
}

int	splited_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int	is_only_contains_one_map(char **raw_lines)
{
	size_t	lines_cnt;
	size_t	i;

	lines_cnt = get_height(raw_lines);
	i = lines_cnt - 1;
	while (i > 0 && raw_lines[i] != NULL && ft_strlen(raw_lines[i]) == 0)
		i--;
	while (i > 0 && raw_lines[i] != NULL
		&& ft_strchr(" 01", raw_lines[i][0]) != NULL
		&& ft_strlen(raw_lines[i]) != 0)
		i--;
	while (i > 0 && raw_lines[i] != NULL && ft_strlen(raw_lines[i]) == 0)
		i--;
	if (ft_strchr("NSWEFC", raw_lines[i][0]) == NULL)
		return (0);
	return (1);
}
