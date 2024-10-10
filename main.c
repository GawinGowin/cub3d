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
	char	*cubfile;

	if (valid_argument(argc, argv))
		return (1);
	cubfile = load_file(argv[1]);
	if (!cubfile)
		return (printerror("Failed to load file"));
	printf("%s\n", cubfile);
	free(cubfile);
	return (0);
}

