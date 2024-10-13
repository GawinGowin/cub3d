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

# define BUFFER_SIZE 600
# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define XPM_SIZE 100
# define ERR_PREFIX "Error: "
# define ERR_INVALID_ARG "Invalid Argument"
# define ERR_WRONG_EXT "File extension is not '.cub'"
# define ERR_NOTHING_EXT "File has no extension"
# define ERR_FAILED_INIT_MLX "Failed to initialize minilibx"
# define ERR_MALLOC "Failed to allocate memory"
# define ERR_FORMAT "Invalid .cub file format"

typedef struct s_param_cub
{
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
	int		floor;
	int		ceiling;
	int		map_width;
	int		map_height;
	char	**map;
}			t_param_cub;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	angle;
}		t_player;

typedef struct s_mlx_val
{
	int		bpp;
	int		line_byte;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
}			t_mlx_val;

typedef struct s_data
{
	t_player	player;
	t_mlx_val	mlx_val;
	t_param_cub	params;
}				t_data;

// parse_cub
int		parse_cub(t_data *data, char *filename);
void	free_2d_array_of_char(char **array);
char	**set_array_from_file(char *filename);
int		get_conf_and_map(t_data *data, char **array);
char	**split_cub(char *file);
int		get_color(char *str);
int		splited_length(char **array);
int		get_conf(t_data *data, char **array);
int		strlen_ln(char *str);
int		free_double_str(char *s1, char *s2, int ret);

int		init_data(t_data *data, char *name);
int		printerror(char *str);
int		valid_argument(int argc, char **argv);
int		destroy_mlx_ptr(t_data *data);
int		detect_close(t_data *data);
int		detect_keys(int key, t_data *data);

#endif
