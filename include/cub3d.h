/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:25:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/20 17:04:27 by saraki           ###   ########.fr       */
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
# include <math.h>

# define BUFFER_SIZE 600
# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define XPM_SIZE 100
# define PI 3.1415926535

// 一歩で進む距離
# define STRIDE 1.0

# define ERR_PREFIX "Error: "
# define ERR_INVALID_ARG "Invalid Argument"
# define ERR_WRONG_EXT "File extension is not '.cub'"
# define ERR_NOTHING_EXT "File has no extension"
# define ERR_FAILED_INIT_MLX "Failed to initialize minilibx"
# define ERR_MALLOC "Failed to allocate memory"
# define ERR_FORMAT "Invalid .cub file format"

# define WALL '1'
# define SPACE ' '
# define PLAYER_NORTH 'N'
# define PLAYER_SOUTH 'S'
# define PLAYER_WEST 'W'
# define PLAYER_EAST 'E'
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define ARROW_R 65363
# define ARROW_L 65361

typedef struct s_param_cub
{
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
	int		floor;
	int		ceiling;
	size_t	map_width;
	size_t	map_height;
	char	**map;
}			t_param_cub;

// angle
// 0 EA, 90 SO, 180 WE, 270 NO
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		angle;
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

// map_utils
char	**dup_map(char **map, size_t height);
void	free_map(char **map, size_t height);
size_t	get_height(char **map);
size_t	get_width(char **map);

// parse_cub
enum e_conf
{
	FLAG_NO = 1,
	FLAG_SO = 2,
	FLAG_WE = 4,
	FLAG_EA = 8,
	FLAG_F = 16,
	FLAG_C = 32,
};

int		parse_cub(t_data *params, char *filename);
void	free_2d_array_of_char(char **array);
char	**set_array_from_file(char *filename);
int		get_conf_and_map(t_data *params, char **array);
char	**split_cub(char *file);
int		color_str_to_int(char *str);
int		splited_length(char **array);
int		get_conf(t_data *data, char **lines);
int		strlen_ln(char *str);

char	**get_map(char **raw_map_lines, size_t width, size_t height);
void	get_mapsize(char **raw_map_lines, size_t *width, size_t *height);

// movement
double	cos_degree(int angle);
double	sin_degree(int angle);
void	update_angle(t_data *data, int key);
void	update_coordinate(t_data *data, int key);
int		regulate_angle(int now);

// t_wall	detect_wall_by_dda(t_data *data, double angle);

int		init_data(t_data *data, char *name);
int		printerror(char *str);
int		valid_argument(int argc, char **argv);
int		destroy_mlx_ptr(t_data *data);
int		detect_close(t_data *data);
int		detect_keys(int key, t_data *data);

// validation
int		is_valid_map(char **map);
int		has_invalid_char(char **map);

#endif
