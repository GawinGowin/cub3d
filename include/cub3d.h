/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:25:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/05 10:49:43 by saraki           ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>

# define BUFFER_SIZE 600
# define WIN_WIDTH 1000
# define WIN_HEIGHT 600

# define PI 3.1415926535
# define FOV 80.0

// one step per move
# define STRIDE 0.1
// one step per rotation
# define ROTATION 1.5
// offset to avoid collision
# define OFFSET 0.05
// initial position fraction of player
# define INIT_FRAC  0.5

# define ERR_PREFIX "Error: "
# define ERR_INVALID_ARG "Invalid Argument"
# define ERR_WRONG_EXT "File extension is not '.cub'"
# define ERR_NOTHING_EXT "File has no extension"
# define ERR_FAILED_INIT_MLX "Failed to initialize minilibx"
# define ERR_FAILED_CREATE_IMG "Failed to create mlx image"
# define ERR_FAILED_RENDERING "Failed to render image"
# define ERR_MALLOC "Failed to allocate memory"
# define ERR_FORMAT "Invalid .cub file format"
# define ERR_LOAD_CUB "Failed to load .cub file"

# define WALL '1'
# define SPACE ' '
# define PLAYER_NORTH 'N'
# define PLAYER_SOUTH 'S'
# define PLAYER_WEST 'W'
# define PLAYER_EAST 'E'

typedef struct s_texture_img
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
}			t_texture;

typedef struct s_param_cub
{
	t_texture		img_no;
	t_texture		img_so;
	t_texture		img_we;
	t_texture		img_ea;
	int				floor;
	int				ceiling;
	size_t			map_width;
	size_t			map_height;
	char			**map;
}			t_param_cub;

// angle
// 0 EA, 90 SO, 180 WE, 270 NO
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
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
	int			is_moving;
}				t_data;

// root
void	load_hooks_and_loop(t_data *data);
int		init_data(t_data *data, char *name);
void	init_values(t_data *data);
int		destroy_mlx_ptr(t_data *data);
void	deinit_exit(t_data *data, int exit_status);
int		printerror(char *str);
void	*printerr_null(char *str);
int		valid_argument(int argc, char **argv);
int		update_screen(t_data *data);
void	output_map_info(t_data *data);

//// map_utils
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
char	*read_loop(int fd);
int		get_conf_and_map(t_data *params, char **array);
char	**split_cub(char *file);
int		get_color(t_data *data, char *str, char *id, int *flag);
int		splited_length(char **array);
int		get_conf(t_data *data, char **lines);
int		is_id_direction(char *id);
int		is_id_color(char *id);
int		is_id_in_line(char *str);
int		is_all_flags(int flags);
void	set_img_stract(t_texture *img, void *img_ptr, int width, int height);
int		strlen_ln(char *str);
char	**get_map(char **raw_map_lines, size_t width, size_t height);
void	get_mapsize(char **raw_map_lines, size_t *width, size_t *height);
int		get_player(t_data *data);

// algo
typedef struct s_side_distination
{
	double	dist[2];
	int		step[2];
}				t_side_dist;

/**
 * @struct s_dda_result
 * @brief Structure to hold the result of the DDA algorithm.
 *
 * This structure is used to store the results obtained
 * from the DDA algorithm, which is typically used in computer
 * graphics to perform ray casting or line drawing.
 */
typedef struct s_dda_result
{
	int			is_hit;
	double		distance;
	size_t		hit_block[2];
	/**
	 * @brief Represents the side of a wall hit during raycasting.
	 * side == 1 : y-side
	 * side == 0 : x-side
	 */
	int			side;
	double		delta_dist[2];
	double		dist_option[2];
	double		ray_distination[2];
	t_side_dist	_side_dist;
}				t_dda;

t_dda	dda(t_player *player, char **map);

// movement
double	cos_degree(double angle);
double	sin_degree(double angle);
void	update_angle(t_data *data, int key);
void	update_coordinate(t_data *data, int key);
double	regulate_angle(double now);

// rendering
int		render_image(t_mlx_val *mlx);
void	put_color_to_img(t_mlx_val *mlx_val, size_t x, size_t y, int color);
int		pick_texture_color(t_data *data, t_dda *dda, double texture_y);
void	render_bg(t_mlx_val *mlx_val, int sky, int ground);
int		render_walls(t_data *data, t_player *player);

// validation
int		is_validate(t_data *data);
int		is_valid_map(char **map);

int		has_invalid_char(char **map, char *available_set);
int		is_contain_only_one_symbol(
			char **map, char *set, size_t height, size_t width);

#endif
