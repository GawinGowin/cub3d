/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:13:23 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 09:31:57 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Parses the cub file and populates the data structure.
 *
 * @param data The pointer to the data structure to be populated.
 * @param filename The path to the cub file to be parsed.
 * @return Returns an integer indicating the success or failure
 * of the parsing process.
 */
int	parse_cub(t_data *data, char *filename)
{
	char	**cubfile_as_array;
	int		status;

	cubfile_as_array = set_array_from_file(filename);
	if (!cubfile_as_array)
	{
		init_values(data);
		return (1);
	}
	status = get_conf_and_map(data, cubfile_as_array);
	free_2d_array_of_char(cubfile_as_array);
	if (status)
	{
		if (data->params.map)
			free_2d_array_of_char(data->params.map);
		init_values(data);
		return (1);
	}
	return (0);
}

void	free_2d_array_of_char(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		free(array[i]);
	}
	free(array);
}
