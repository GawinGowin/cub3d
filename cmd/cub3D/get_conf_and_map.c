/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_and_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamasaw <syamasaw@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 09:55:33 by syamasaw          #+#    #+#             */
/*   Updated: 2024-10-11 09:55:33 by syamasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	splited_length(char **array);
// static void	get_size_map(t_data *data, char **array, int i);
// static int	get_map(t_data *data, char **array, int i);
static int	detect_identifier(t_data *data, char **array);

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	get_conf_and_map(t_data *data, char **array)
{
	int		i;
	char	**tmp;

	(void)data;
	i = -1;
	// confを取得する用ループ
	while (array[++i] && array[i][0])
	{
		// 空行飛ばし
		if (array[i][0] == '\n')
			continue ;
		// 先頭文字が識別子以外ならbreak
		if (ft_strchr("NSWEFC", array[i][0]) == NULL)
			break ;
		// split
		tmp = ft_split(array[i], ' ');
		// split後の分割数が2ではないならエラー
		// tmp[0]が識別子に一致しないならエラー
		// 一致するなら、tmp[1]をパスとして開く
		detect_identifier(data, tmp);
		free_array(tmp);
	}
	// 設定部分を全て取ったらbreak
	// breakしたときに設定が全て取れていないならエラー
	return (0);
}

// 1. mapのheight、widthを求める
// 2. mapをmallocする
// 3. mapに値をコピーする
// static int	get_map(t_data *data, char **array, int i)
// {
// 	get_size_map(data, array, i);
// 	printf("w %d, h %d\n", data->params.map_width, data->params.map_height);
// 	return (data->params.map_height);
// }

// static void	get_size_map(t_data *data, char **array, int i)
// {
// 	int	w;
// 	int	h;
// 	int	tmp;

// 	w = 0;
// 	h = 0;
// 	while ((i >= 0 && array[i][0] != '\0'))
// 	{
// 		printf("%c", array[i][0]);
// 		tmp = 0;
// 		tmp = ft_strlen(array[i]);
// 		if (tmp > w)
// 			w = tmp;
// 		i--;
// 		h++;
// 	}
// 	data->params.map_height = h;
// 	data->params.map_width = w;
// }

static int	detect_identifier(t_data *data, char **array)
{
	(void)data;
	if (splited_length(array) != 2)
		return (1);
	printf("%s\n", array[0]);
	// if (ft_strcmp(array[0], "F") == 0)
	// 	a;
	// else if (ft_strcmp(array[0], "C") == 0)
	// 	a;
	// else if (ft_strcmp(array[0], "NO") == 0)
	// 	a;
	// else if (ft_strcmp(array[0], "SO") == 0)
	// 	a;
	// else if (ft_strcmp(array[0], "WE") == 0)
	// 	a;
	// else if (ft_strcmp(array[0], "EA") == 0)
	// 	a;
	// else
	// 	return (1);
	return (0);
}

static int	splited_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
