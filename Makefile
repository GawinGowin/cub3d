all:
	cc *.c -o cub3D -lmlx_Linux -lXext -lX11 -fsanitize=address -g

fclean:
	rm -f cub3D