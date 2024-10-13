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
	if (get_conf_and_map(data, cubfile))
	{
		free_2d_array_of_char(cubfile);
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
