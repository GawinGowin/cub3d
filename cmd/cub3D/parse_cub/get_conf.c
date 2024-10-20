/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 08:20:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/20 17:05:33 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_conf_by_str(t_data *param, char *str, int *flags);
static int	detect_identifier(t_data *data, char **key_value, int *flag);
static int	get_img(t_data *data, char *path, char *id, int *flag);
static void set_flag(char *id, int *flag);

/**
 * Parses the configuration for the cub3D game.
 *
 * @param param - Pointer to the t_param_cub struct to store the parsed
 * configuration.
 * @param array - Array of strings containing the configuration data.
 * @return int - Returns 0 on success, -1 on failure.
 */
int	get_conf(t_data *data, char **lines)
{
	int	i;
	int	code;
	int	flags;

	flags = 0;
	i = 0;
	while (lines[i] && (!ft_strncmp(lines[i], "NO", 2)
			|| !ft_strncmp(lines[i], "SO", 2) || !ft_strncmp(lines[i], "WE", 2)
			|| !ft_strncmp(lines[i], "EA", 2) || !ft_strncmp(lines[i], "F", 1)
			|| !ft_strncmp(lines[i], "C", 1)))
	{
		code = get_conf_by_str(data, lines[i], &flags);
		if (code < 0)
			return (-1);
		else if (code == 1)
			break ;
		i ++;
	}
	return (0);
}

static int	get_conf_by_str(t_data *data, char *str, int *flags)
{
	char	**key_value;
	int		code;

	key_value = ft_split(str, ' ');
	if (!key_value)
		return (-1);
	code = detect_identifier(data, key_value, flags);
	free_2d_array_of_char(key_value);
	if (code == -2)
		printerror(ERR_MALLOC);
	else if (code == -1)
		printerror(ERR_FORMAT);
	return (code);
}

/**
 * Detects the identifier in the given data structure.
 *
 * @param data The data structure containing the configuration information.
 * @param key_value The key-value pair to be analyzed.
 * @param flag The flag indicating the detection status.
 * @return The result of the detection process.
 * Return values:
 * - 0: Identifier detected.
 * - 1: Non-identifier detected.
 * - -1: Error occurred.
 * - -2: Memory allocation (malloc) error.
 */
static int	detect_identifier(t_data *data, char **key_value, int *flag)
{
	char	*key;
	char	*path_or_color;

	if (splited_length(key_value) != 2)
		return (-1);
	key = key_value[0];
	path_or_color = key_value[1];
	if (ft_strcmp(key, "F") == 0 && !((*flag) & FLAG_F))
		data->params.floor = color_str_to_int(path_or_color);
	else if (ft_strcmp(key, "C") == 0 && !((*flag) & FLAG_C))
		data->params.ceiling = color_str_to_int(path_or_color);
	else if (ft_strcmp(key, "NO") == 0 || (ft_strcmp(key, "SO") == 0)
		|| (ft_strcmp(key, "WE") == 0) || (ft_strcmp(key, "EA") == 0))
		get_img(data, path_or_color, key, flag);
	else
		return (-1);
	if (ft_strcmp(key, "F") == 0)
		(*flag) |= FLAG_F;
	else if (ft_strcmp(key, "C") == 0)
		(*flag) |= FLAG_C;
	return (0);
}

static int	get_img(t_data *data, char *path, char *id, int *flag)
{
	int	w;
	int	h;

	w = XPM_SIZE;
	h = XPM_SIZE;
	if (ft_strcmp(id, "NO") == 0 && !((*flag) & FLAG_NO))
		data->params.img_no = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr,
				path, &w, &h);
	else if (ft_strcmp(id, "SO") == 0 && !((*flag) & FLAG_SO))
		data->params.img_so = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr,
				path, &w, &h);
	else if (ft_strcmp(id, "WE") == 0 && !((*flag) & FLAG_WE))
		data->params.img_we = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr,
				path, &w, &h);
	else if (ft_strcmp(id, "EA") == 0 && !((*flag) & FLAG_EA))
		data->params.img_ea = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr,
				path, &w, &h);
	else
		return (-1);
	set_flag(id, flag);
	return (0);
}

static void	set_flag(char *id, int *flag)
{
	if (ft_strcmp(id, "NO") == 0)
		*flag |= FLAG_NO;
	else if (ft_strcmp(id, "SO") == 0)
		*flag |= FLAG_SO;
	else if (ft_strcmp(id, "WE") == 0)
		*flag |= FLAG_WE;
	else if (ft_strcmp(id, "EA") == 0)
		*flag |= FLAG_EA;
}
