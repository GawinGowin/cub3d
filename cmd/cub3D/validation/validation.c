/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:04:08 by saraki            #+#    #+#             */
/*   Updated: 2024/11/04 09:37:59 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_data_satisfies(t_data *data);

/**
 * @brief Validates the provided data structure.
 *
 * This function checks the integrity and correctness of the data contained
 * within the t_data structure. It ensures that all necessary fields are
 * properly initialized and meet the required criteria for further processing.
 *
 * @param data A pointer to the t_data structure to be validated.
 * @return An integer indicating the validation result.
 *         Returns 1 if the data is valid, 0 otherwise.
 */
int	is_validate(t_data *data)
{
	if (is_data_satisfies(data) && is_valid_map(data->params.map))
		return (1);
	printerror(ERR_FORMAT);
	return (0);
}

static int	is_data_satisfies(t_data *data)
{
	if (data == NULL || data->params.map == NULL)
		return (0);
	if (!data->params.img_no.img || !data->params.img_so.img
		|| !data->params.img_ea.img || !data->params.img_we.img)
		return (0);
	if (data->params.ceiling < 0 || data->params.floor < 0)
		return (0);
	if (data->params.map_width == 0 || data->params.map_height == 0
		|| data->params.map_width > INT_MAX
		|| data->params.map_height > INT_MAX)
		return (0);
	if (!(data->player.pos_x > 0) || !(data->player.pos_y > 0)
		|| !(data->player.pos_x < data->params.map_width - 1)
		|| !(data->player.pos_y < data->params.map_height - 1))
		return (0);
	if (!(data->player.angle == 0) && !(data->player.angle == 90)
		&& !(data->player.angle == 180) && !(data->player.angle == 270))
		return (0);
	return (1);
}
