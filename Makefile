all:
	cc *.c -o cub3D -lmlx_Linux -lXext -lX11 -fsanitize=address -g

normal:
	cc *.c -o cub3D -lmlx_Linux -lXext -lX11

fclean:
	rm -f cub3D