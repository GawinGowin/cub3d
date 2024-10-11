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

// libft置換予定

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

static size_t	count_word(char const *s, char c)
{
	long int	pos;
	size_t		word_cnt;

	pos = 0;
	word_cnt = 0;
	while (s[pos] != '\0')
	{
		if ((pos == 0 && s[pos] != c) || (s[pos - 1] == c && s[pos] != c))
			word_cnt++;
		pos++;
	}
	return (word_cnt);
}

static size_t	word_len(char const *s, char c, size_t i)
{
	long int	pos;
	size_t		word_len;
	size_t		word_pos;
	long int	start;

	pos = -1;
	word_pos = 0;
	while (s[++pos] != '\0')
	{
		if ((pos == 0 && s[pos] != c) || (s[pos - 1] == c && s[pos] != c))
		{
			word_len = 0;
			if (word_pos == i)
			{
				start = pos - 1;
				while (s[++start] != c && s[start] != '\0')
					word_len++;
				break ;
			}
			word_pos++;
		}
	}
	return (word_len);
}

static int	word_head_pos(char const *s, char c, int i)
{
	int	pos;
	int	word_pos;

	pos = 0;
	word_pos = 0;
	while (s[pos] != '\0')
	{
		if ((pos == 0 && s[pos] != c) || (s[pos - 1] == c && s[pos] != c))
		{
			if (word_pos == i)
				return (pos);
			word_pos++;
		}
		pos++;
	}
	return (0);
}

static void	free_mem(char **str, size_t i)
{
	while (i-- > 0)
		free(str[i]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	word_cnt;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_cnt = count_word(s, c);
	ret = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (i < word_cnt)
	{
		ret[i] = ft_substr(s, word_head_pos(s, c, i), word_len(s, c, i));
		if (ret[i] == NULL)
		{
			free_mem(ret, i);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len || len < 1)
	{
		sub = (char *)malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	if (len < s_len - start)
		sub_len = len;
	else
		sub_len = s_len - start;
	sub = (char *)malloc((sub_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
