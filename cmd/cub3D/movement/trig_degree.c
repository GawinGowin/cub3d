/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_degree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 04:18:25 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-15 04:18:25 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cos_degree(int angle)
{
	double	rad;

	rad = angle * (PI / 180.0);
	return (cos(rad));
}

double	sin_degree(int angle)
{
	double	rad;

	rad = angle * (PI / 180.0);
	return (sin(rad));
}
