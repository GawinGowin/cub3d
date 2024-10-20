/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:04:08 by saraki            #+#    #+#             */
/*   Updated: 2024/10/20 17:13:38 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int data_satisfies(t_data *data);

int		validation(t_data *data)
{
	if (data_satisfies(data))
		return (printerror(ERR_FORMAT));
	if (!is_valid_map(data->params.map))
		return (printerror(ERR_FORMAT));
	return (0);
}

static int data_satisfies(t_data *data)
{
	if (data->params.img_no && data->params.img_so && data->params.img_ea
		&& data->params.img_we && data->params.ceiling >= 0
		&& data->params.floor >= 0)
		return (0);
	return (-1);
}
