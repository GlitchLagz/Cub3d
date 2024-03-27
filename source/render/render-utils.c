/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:46:07 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 12:55:26 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	*map_convert_two(t_program *pro, char **map, int c, int *res)
{
	int	d;

	d = 0;
	while (map[d] && d < pro->mapy)
	{
		c = 0;
		while (map[d][c] && c < pro->mapx)
		{
			res[d * pro->mapx + c] = map[d][c] - '0';
			c++;
		}
		while (c < pro->mapx)
		{
			res[d * pro->mapx + c] = 0;
			c++;
		}
		d++;
	}
	return (res);
}

int	*map_convert(char **map, t_program *pro)
{
	int	*res;
	int	*cpy;
	int	c;

	pro->mapy = ft_lstlen(map);
	pro->mapx = ft_strlen(map[1]);
	pro->map_array_len = pro->mapx * pro->mapy;
	pro->map_s = 64;
	res = malloc(sizeof(int) * pro->map_array_len);
	if (res == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	c = 0;
	cpy = map_convert_two(pro, map, c, res);
	return (cpy);
}
