/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:53:12 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 17:52:26 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_extention(char *str);

int	printerror(char *str)
{
	int	i;

	i = -1;
	write(2, ERR_PREFIX, ft_strlen(ERR_PREFIX));
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 2);
	return (1);
}

void	*printerr_null(char *str)
{
	printerror(str);
	return (NULL);
}

int	valid_argument(int argc, char **argv)
{
	if (argc != 2)
		return (printerror(ERR_INVALID_ARG));
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
			return (printerror(ERR_WRONG_EXT));
	}
	return (printerror(ERR_NOTHING_EXT));
}
