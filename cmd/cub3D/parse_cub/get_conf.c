/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 08:20:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-13 08:20:46 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	detect_identifier(t_data *data, char **array);
static int	check_conf_complete(t_data *data);
static void	get_img(t_data *data, char *path, char *id);
static int	get_conf_by_str(t_data *data, char *str);

int	get_conf(t_data *data, char **array)
{
	int		i;
	int		code;

	i = -1;
	while (array[++i] && array[i][0])
	{
		if (array[i][0] == '\n')
			continue ;
		if (ft_strchr("NSWEFC", array[i][0]) == NULL)
			break ;
		code = get_conf_by_str(data, array[i]);
		if (code < 0)
			return (-1);
		else if (code == 1)
			break ;
		if (check_conf_complete(data) == 0)
			break ;
	}
	if (check_conf_complete(data) == 1)
	{
		printerror(ERR_FORMAT);
		return (-1);
	}
	return (i);
}

static int	get_conf_by_str(t_data *data, char *str)
{
	char	**tmp;
	int		code;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (-1);
	code = 0;
	code = detect_identifier(data, tmp);
	free_2d_array_of_char(tmp);
	if (code == -2)
		printerror(ERR_MALLOC);
	else if (code == -1)
		printerror(ERR_FORMAT);
	return (code);
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

// 識別子:0
// 識別子以外:1
// エラー:-1
// mallocエラー:-2
static int	detect_identifier(t_data *data, char **array)
{
	char	*id;
	char	*path;

	if (splited_length(array) != 2)
		return (-1);
	id = ft_strtrim(array[0], "\n");
	if (!id)
		return (-2);
	path = ft_strtrim(array[1], "\n");
	if (!path)
		return (free_double_str(id, NULL, -2));
	if (ft_strcmp(id, "F") == 0)
		data->params.floor = get_color(path);
	else if (ft_strcmp(id, "C") == 0)
		data->params.ceiling = get_color(path);
	else if (ft_strcmp(id, "NO") == 0 || (ft_strcmp(id, "SO") == 0)
		|| (ft_strcmp(id, "WE") == 0) || (ft_strcmp(id, "EA") == 0))
		get_img(data, path, id);
	else
		return (free_double_str(id, path, 1));
	return (free_double_str(id, path, 0));
}

static void	get_img(t_data *data, char *path, char *id)
{
	int	w;
	int	h;

	w = XPM_SIZE;
	h = XPM_SIZE;
	if (ft_strcmp(id, "NO") == 0)
		data->params.img_no = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, path,
				&w, &h);
	else if (ft_strcmp(id, "SO") == 0)
		data->params.img_so = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, path,
				&w, &h);
	else if (ft_strcmp(id, "WE") == 0)
		data->params.img_we = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, path,
				&w, &h);
	else if (ft_strcmp(id, "EA") == 0)
		data->params.img_ea = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, path,
				&w, &h);
}
