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

// static int	splited_length(char **array);
// static void	get_size_map(t_data *data, char **array, int i);
// static int	get_map(t_data *data, char **array, int i);

int	get_conf_and_map(t_data *data, char **array)
{
	int		i;

	(void)data;
	i = -1;
	while (array[++i] && array[i][0])
	{
		if (array[i][0] == '\n')
			continue ;
		printf("> %s", array[i]);
	}
	printf("\n");
	return (0);
}

// 1. mapのheight、widthを求める
// 2. mapをmallocする
// 3. mapに値をコピーする
// static int	get_map(t_data *data, char **array, int i)
// {
// 	get_size_map(data, array, i);
// 	printf("w %d, h %d\n", data->params.map_width, data->params.map_height);
// 	return (data->params.map_height);
// }

// static void	get_size_map(t_data *data, char **array, int i)
// {
// 	int	w;
// 	int	h;
// 	int	tmp;

// 	w = 0;
// 	h = 0;
// 	while ((i >= 0 && array[i][0] != '\0'))
// 	{
// 		printf("%c", array[i][0]);
// 		tmp = 0;
// 		tmp = ft_strlen(array[i]);
// 		if (tmp > w)
// 			w = tmp;
// 		i--;
// 		h++;
// 	}
// 	data->params.map_height = h;
// 	data->params.map_width = w;
// }

// static int	detect_identifier(t_data *data, char **array)
// {
// 	if (splited_length(array) != 2)
// 		return (0);
// 	if (ft_strcmp(array[0], "NO") == 0)
// 		a;
// 	else if (ft_strcmp(array[0], "SO") == 0)
// 		a;
// 	else if (ft_strcmp(array[0], "WE") == 0)
// 		a;
// 	else if (ft_strcmp(array[0], "EA") == 0)
// 		a;
// 	else if (ft_strcmp(array[0], "F") == 0)
// 		a;
// 	else if (ft_strcmp(array[0], "C") == 0)
// 		a;
// 	return (0);
// }

// static int	splited_length(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 		i++;
// 	return (i);
// }
