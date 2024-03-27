/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:28:56 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:18:24 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_parameter(t_program *pro)
{
	surround_map_sides(pro->map);
	pro->map_i = 0;
	find_player(pro);
	if (pro->x == 0 || pro->y == 0)
		error_exit("Player Character Not Found!",
			PARSE_ERROR, pro);
	pro->map_c = ft_tabdup(pro->map);
	pro->floor_c = count_floor_tiles(pro->map_c);
	fill_the_floor(pro, pro->x, pro->y, 'X');
	if (pro->floor_c != 0)
		error_exit("Map Has Hidden Spaces, Knock A Wall Down!",
			PARSE_ERROR, pro);
}

void	fill_the_floor(t_program *pro, int x, int y, char paint)
{
	if (pro->map_c[y][x] == '1')
		return ;
	else if (pro->map_c[y][x] == '0')
	{
		pro->map_c[y][x] = paint;
		pro->floor_c--;
	}
	else if (pro->map_c[y][x] == paint)
		return ;
	else if (pro->map_c[y][x] == 'z')
		error_exit("The walls are leaking again!",
			PARSE_ERROR, pro);
	fill_the_floor(pro, x + 1, y, paint);
	fill_the_floor(pro, x - 1, y, paint);
	fill_the_floor(pro, x, y + 1, paint);
	fill_the_floor(pro, x, y - 1, paint);
}

int	count_floor_tiles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	surround_map_sides(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (i < ft_lstlen(map))
	{
		k = ft_strlen(map[i]);
		while (k != -1)
		{
			if (map[i][k] == ' ')
				map[i][k] = 'z';
			k--;
		}
		i++;
	}
}
