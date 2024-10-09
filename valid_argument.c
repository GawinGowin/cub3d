/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 03:53:12 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 03:53:12 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_extention(char *str);

int	printerror(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	valid_argument(int argc, char **argv)
{
	if (argc != 2)
		return (printerror("Invalid Argument"));
	return (valid_extention(argv[1]));
}

static int	valid_extention(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext)
	{
		if (ft_strcmp(ext, ".cub") == 0)
			return (0);
		else
			return (printerror("File extension is not '.cub'"));
	}
	return (printerror("File has no extension"));
}
