/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:37:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/20 04:46:46 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allocate_oneline(char *file, int start, int len);
static int	get_split_len(char *file);
static int	count_nl(char *file);
static void	free_array(char **array, int i);

char	**split_cub(char *file)
{
	char	**array;
	int		size;
	int		i;
	int		start;
	int		len;

	size = count_nl(file) + 1;
	array = (char **)malloc((size + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < size)
	{
		len = get_split_len(file + start);
		array[i] = allocate_oneline(file, start, len);
		if (!array[i])
		{
			free_array(array, i);
			return (NULL);
		}
		start += len;
	}
	array[i] = NULL;
	return (array);
}

static char	*allocate_oneline(char *file, int start, int len)
{
	char	*line;
	char	*line_without_nl;

	line = ft_substr(file, start, len);
	if (!line)
		return (NULL);
	line_without_nl = ft_strtrim(line, "\n");
	free(line);
	if (!line_without_nl)
		return (NULL);
	return (line_without_nl);
}

static int	get_split_len(char *file)
{
	int	i;

	i = 0;
	while ((file[i] != '\0' && file[i] != '\n'))
		i++;
	if ((file[i] == '\0' || file[i] == '\n'))
		i++;
	return (i);
}

static void	free_array(char **array, int i)
{
	while (--i >= 0)
		free(array[i]);
	free(array);
}

static int	count_nl(char *file)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (file[++i])
		if (file[i] == '\n')
			cnt++;
	return (cnt);
}
