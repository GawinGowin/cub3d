/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_degree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:18:25 by syamasaw          #+#    #+#             */
/*   Updated: 2024/10/26 22:44:20 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cos_degree(int angle)
{
	double	rad;
	double	ret;

	rad = angle * (PI / 180.0);
	ret = cos(rad);
	if (fabs(ret) < EPSILON)
		ret = 0;
	return (ret);
}

double	sin_degree(int angle)
{
	double	rad;
	double	ret;

	rad = angle * (PI / 180.0);
	ret = sin(rad);
	if (fabs(ret) < EPSILON)
		ret = 0;
	return (ret);
}
