/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:26:24 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/04 19:26:46 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	output_color(int floor, int ceiling);

void	output_map_info(t_data *data)
{
	int	i;

	i = -1;
	printf("MapSize\nwidth: %zu\nheight: %zu\n\n",
		data->params.map_width, data->params.map_height);
	output_color(data->params.floor, data->params.ceiling);
	printf("Map\n");
	while (data->params.map[++i])
		printf("%d %s\n", i, data->params.map[i]);
}

static void	output_color(int floor, int ceiling)
{
	int	rgb[3];

	printf("HexColor\n");
	rgb[0] = (floor >> 16) & 0xFF;
	rgb[1] = (floor >> 8) & 0xFF;
	rgb[2] = floor & 0xFF;
	printf("floor: \033[48;2;%d;%d;%d;1m%x\033[0m\n", \
		rgb[0], rgb[1], rgb[2], floor);
	rgb[0] = (ceiling >> 16) & 0xFF;
	rgb[1] = (ceiling >> 8) & 0xFF;
	rgb[2] = ceiling & 0xFF;
	printf("ceiling: \033[48;2;%d;%d;%d;1m%x\033[0m\n", \
		rgb[0], rgb[1], rgb[2], ceiling);
}