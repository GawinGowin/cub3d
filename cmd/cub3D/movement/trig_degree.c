/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_degree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saraki <saraki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:18:25 by syamasaw          #+#    #+#             */
/*   Updated: 2024/11/03 00:38:08 by saraki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cos_degree(double angle)
{
	double	rad;

	rad = angle * (PI / 180.0);
	return (cos(rad));
}

double	sin_degree(double angle)
{
	double	rad;

	rad = angle * (PI / 180.0);
	return (sin(rad));
}
