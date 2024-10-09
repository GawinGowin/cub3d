/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 03:25:29 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-09 03:25:29 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		printerror(char *str);
int		valid_argument(int argc, char **argv);

// libftの関数
char	*ft_strrchr(const char *s, int c);

// libft外の関数
int		ft_strcmp(const char *s1, const char *s2);

#endif