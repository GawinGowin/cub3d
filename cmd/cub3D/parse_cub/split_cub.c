/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 10:37:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-12 10:37:46 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_sprit_len(char *file);
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
		len = get_sprit_len(file + start);
		array[i] = ft_substr(file, start, len);
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

static int	get_sprit_len(char *file)
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
