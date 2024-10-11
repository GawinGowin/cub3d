/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 03:25:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 03:25:29 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 600
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 600
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 600
# endif

typedef struct s_cub3d
{
	int		bpp;
	int		line_byte;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	char	**cubfile_array;
}			t_cub3d;

int		printerror(char *str);
int		valid_argument(int argc, char **argv);
char	**set_array_from_file(char *filename);

// libftの関数
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);

// libft外の関数
int		ft_strcmp(const char *s1, const char *s2);

#endif