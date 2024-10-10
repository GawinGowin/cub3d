/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 03:19:21 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 03:19:21 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	while (!(s1[i] == '\0' && s2[i] == '\0'))
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return ((int)(c1 - c2));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*s1s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s1s2 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (s1s2 == NULL)
		return (NULL);
	ft_memcpy(s1s2, s1, lens1);
	ft_memcpy(s1s2 + lens1, s2, lens2 + 1);
	return (s1s2);
}

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;

	if (dest == NULL && src == NULL)
		return (NULL);
	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
		*de++ = *sr++;
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (size > SIZE_MAX / count)
		return (NULL);
	cal = (void *)malloc(size * count);
	if (cal == NULL)
		return (NULL);
	ft_memset(cal, 0, size * count);
	return (cal);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *)ptr;
	c = (unsigned char)value;
	while (num--)
		*str++ = c;
	return (ptr);
}
