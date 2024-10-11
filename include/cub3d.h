/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:25:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/12 07:15:13 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"

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
# define ERR_PREFIX "Error: "
# define ERR_INVALID_ARG "Invalid Argument"
# define ERR_WRONG_EXT "File extension is not '.cub'"
# define ERR_NOTHING_EXT "File has no extension"
# define ERR_FAILED_INIT_MLX "Failed to initialize minilibx"
# define ERR_MALLOC "Failed to allocate memory"

typedef struct s_cub3d
{
	int		pos_x;
	int		pos_y;
	int		angle;
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
int		destroy_mlx_ptr(t_cub3d *data);
int		detect_close(t_cub3d *data);
int		detect_keys(int key, t_cub3d *data);

#endif
