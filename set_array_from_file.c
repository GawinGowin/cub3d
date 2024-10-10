/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-10 09:45:26 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-10 09:45:26 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*read_loop(int fd);
static char	*allfree(char *s1, char *s2);
static char	*strjoin_allfree(char *s1, char *s2);
static char	*load_file(char *filename);

char	**set_array_from_file(char *filename)
{
	char	*file;
	char	**array;

	file = load_file(filename);
	if (!file)
		return (NULL);
	array = ft_split(file, '\n');
	free(file);
	if (!array)
		return (NULL);
	return (array);
}

static char	*load_file(char *filename)
{
	char	*text;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text = read_loop(fd);
	close(fd);
	if (!text)
		return (NULL);
	return (text);
}

static char	*allfree(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*strjoin_allfree(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	allfree(s1, s2);
	return (ret);
}

static char	*read_loop(int fd)
{
	char	*text;
	char	*buf;
	int		byte;

	text = (char *)ft_calloc(1, 1);
	if (!text)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buf)
			return (allfree(text, buf));
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (allfree(text, buf));
		else if (byte == 0)
			break ;
		text = strjoin_allfree(text, buf);
		if (!text)
			return (NULL);
	}
	free(buf);
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
