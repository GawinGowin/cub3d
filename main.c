/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 02:50:34 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 02:50:34 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	char	**cubfile_array;
	int		i;

	if (valid_argument(argc, argv))
		return (1);
	cubfile_array = set_array_from_file(argv[1]);
	if (!cubfile_array)
		return (1);
	// 確認用
	while (cubfile_array[i])
	{
		printf("> %s\n", cubfile_array[i]);
		free(cubfile_array[i]);
		i++;
	}
	free(cubfile_array);
	return (0);
}

