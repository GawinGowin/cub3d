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

// static void	get_size_map(t_data *data, char **array, int i);
// static int	get_map(t_data *data, char **array, int i);
static int	detect_identifier(t_data *data, char **array);
static int	check_conf_complete(t_data *data);

int	get_conf_and_map(t_data *data, char **array)
{
	int		i;
	char	**tmp;

	i = -1;
	// confを取得する用ループ
	while (array[++i] && array[i][0])
	{
		if (array[i][0] == '\n')
			continue ;
		if (ft_strchr("NSWEFC", array[i][0]) == NULL)
			break ;
		tmp = ft_split(array[i], ' ');
		if (detect_identifier(data, tmp))
		{
			free_2d_array_of_char(tmp);
			break ;
		}
		free_2d_array_of_char(tmp);
		if (check_conf_complete(data) == 0)
			break ;
	}
	if (check_conf_complete(data) == 1)
	{
		printf("KO\n");
		return (1);
	}
	return (0);
}

static int	check_conf_complete(t_data *data)
{
	if (!data->params.img_no)
		return (1);
	if (!data->params.img_so)
		return (1);
	if (!data->params.img_ea)
		return (1);
	if (!data->params.img_we)
		return (1);
	if (data->params.ceiling < 0)
		return (1);
	if (data->params.floor < 0)
		return (1);
	return (0);
}

static int	detect_identifier(t_data *data, char **array)
{
	int	w;
	int	h;
	char	*str;

	w = XPM_SIZE;
	h = XPM_SIZE;
	if (splited_length(array) != 2)
		return (1);
	str = ft_strtrim(array[1], "\n");
	printf("%s %s\n", array[0], str);
	if (ft_strcmp(array[0], "F") == 0)
		data->params.floor = get_color(array[1]);
	else if (ft_strcmp(array[0], "C") == 0)
		data->params.ceiling = get_color(array[1]);
	else if (ft_strcmp(array[0], "NO") == 0)
		data->params.img_no = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, array[1], &w, &h);
	else if (ft_strcmp(array[0], "SO") == 0)
		data->params.img_so = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, array[1], &w, &h);
	else if (ft_strcmp(array[0], "WE") == 0)
		data->params.img_we = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, array[1], &w, &h);
	else if (ft_strcmp(array[0], "EA") == 0)
		data->params.img_ea = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, array[1], &w, &h);
	else
	{
		free(str);
		return (1);
	}
	free(str);
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