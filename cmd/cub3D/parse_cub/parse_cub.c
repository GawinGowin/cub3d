/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 05:13:23 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-13 05:13:23 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_cub(t_data *data, char *filename)
{
	char	**cubfile;

	cubfile = set_array_from_file(filename);
	if (!cubfile)
		return (1);
	if (cubfile[0][0] == '\0')
	{
		free_2d_array_of_char(cubfile);
		return (printerror(ERR_FORMAT));
	}
	if (get_conf_and_map(data, cubfile))
	{
		free_2d_array_of_char(cubfile);
		free_2d_array_of_char(data->params.map);
		return (1);
	}
	free_2d_array_of_char(cubfile);
	return (0);
}

void	free_2d_array_of_char(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	free_double_str(char *s1, char *s2, int ret)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (ret);
}
