/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:45:26 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 17:51:00 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*load_file(char *filename);

char	**set_array_from_file(char *filename)
{
	char	*file;
	char	**array;

	file = load_file(filename);
	if (!file)
		return (NULL);
	array = split_cub(file);
	free(file);
	if (!array)
		return (printerr_null(ERR_MALLOC));
	return (array);
}

static char	*load_file(char *filename)
{
	char	*text;
	int		fd;

	if (BUFFER_SIZE < 1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printerr_null(ERR_LOAD_CUB));
	else if (read(fd, 0, 0) < 0)
	{
		close(fd);
		return (printerr_null(ERR_LOAD_CUB));
	}
	text = read_loop(fd);
	close(fd);
	if (!text)
		return (NULL);
	return (text);
}

// int main(void)
// {
// 	char *text;

// 	text = load_cub_file("load_cub_file.c");
// 	printf("%s\n", text);
// 	free(text);
// 	return (0);
// }
