/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 08:20:46 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/29 22:48:07 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_conf_by_str(t_data *param, char *str, int *flags);
static int	detect_identifier(t_data *data, char **key_value, int *flag);
static int	get_img(t_data *data, char *path, char *id, int *flag);
static void	set_flag(char *id, int *flag);

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
	while (lines[i] && is_id_in_line(lines[i]))
	{
		code = get_conf_by_str(data, lines[i], &flags);
		if (code < 0)
			return (-1);
		else if (code == 1)
			break ;
		i ++;
	}
	if (!is_all_flags(flags))
	{
		printerror(ERR_FORMAT);
		return (-1);
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
	int		code;

	if (splited_length(key_value) != 2)
		return (-1);
	key = key_value[0];
	path_or_color = key_value[1];
	if (is_id_color(key))
		code = get_color(data, path_or_color, key, flag);
	else if (is_id_direction(key))
		code = get_img(data, path_or_color, key, flag);
	else
		return (-1);
	return (code);
}

static int	get_img(t_data *data, char *path, char *id, int *flag)
{
	int		w;
	int		h;
	void	*img;

	w = XPM_SIZE;
	h = XPM_SIZE;
	img = NULL;
	img = mlx_xpm_file_to_image(data->mlx_val.mlx_ptr, path, &w, &h);
	if (!img)
		return (-1);
	if (ft_strcmp(id, "NO") == 0 && !((*flag) & FLAG_NO))
		data->params.img_no = img;
	else if (ft_strcmp(id, "SO") == 0 && !((*flag) & FLAG_SO))
		data->params.img_so = img;
	else if (ft_strcmp(id, "WE") == 0 && !((*flag) & FLAG_WE))
		data->params.img_we = img;
	else if (ft_strcmp(id, "EA") == 0 && !((*flag) & FLAG_EA))
		data->params.img_ea = img;
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
