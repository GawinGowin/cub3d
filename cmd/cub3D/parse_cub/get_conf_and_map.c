/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_and_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:33 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/17 15:20:08 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map(t_data *data, char **array, int i);
static void	get_size_of_map(t_data *data, char **array, int i);
static int	copy_map(t_data *data, char **array, int i);

int	get_conf_and_map(t_data *data, char **array)
{
	int	i;
	int	j;

	j = 0;
	while (array[j] && array[j][0] == '\n')
		j++;
	if (array[j][0] == '\0')
		return (printerror(ERR_FORMAT));
	i = 0;
	i = get_conf(data, array);
	if (i < 0)
		return (1);
	// data->params.map = get_map()
	// if (get_map(data, array, i + 1))
	// 	return (1);
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
