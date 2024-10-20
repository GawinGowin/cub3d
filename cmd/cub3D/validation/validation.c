/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:04:08 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 19:50:12 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_data_satisfies(t_data *data);

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
	if (!data->params.img_no)
		return (0);
	if (!data->params.img_so)
		return (0);
	if (!data->params.img_ea)
		return (0);
	if (!data->params.img_we)
		return (0);
	if (data->params.ceiling < 0)
		return (0);
	if (data->params.floor < 0)
		return (0);
	if (data->params.map_width == 0 || data->params.map_height == 0)
		return (0);
	return (1);
}
