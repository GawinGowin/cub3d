/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:04 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 17:49:21 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*allfree(char *s1, char *s2);
static char	*strjoin_allfree(char *s1, char *s2);
static char	*calloc_buf(void);
static int	read_wrapper(int fd, char *buf);

char	*read_loop(int fd)
{
	char	*text;
	char	*buf;
	int		byte;

	text = (char *)ft_calloc(1, 1);
	if (!text)
		return (printerr_null(ERR_MALLOC));
	byte = 1;
	while (byte > 0)
	{
		buf = calloc_buf();
		if (!buf)
			return (allfree(text, buf));
		byte = read_wrapper(fd, buf);
		if (byte < 0)
			return (allfree(text, buf));
		else if (byte == 0)
			break ;
		text = strjoin_allfree(text, buf);
		if (!text)
			return (printerr_null(ERR_MALLOC));
	}
	free(buf);
	return (text);
}

static int	read_wrapper(int fd, char *buf)
{
	int	byte;

	byte = read(fd, buf, BUFFER_SIZE);
	if (byte < 0)
	{
		printerror(ERR_LOAD_CUB);
		return (-1);
	}
	return (byte);
}

static char	*calloc_buf(void)
{
	char	*buf;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		printerror(ERR_MALLOC);
	return (buf);
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
