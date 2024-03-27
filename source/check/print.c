/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:28:56 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 11:53:39 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(char **map)
{
	int	i;
	int	q;

	i = 0;
	while (map[i])
	{
		q = 0;
		while (map[i][q] != '|')
		{
			if (map[i][q] == 'z')
				printf("\e[1;31m%c\e[1;32m", map[i][q]);
			else if (map[i][q] == 'X' || map[i][q] == '0')
				printf("\e[0;33m%c\e[1;32m", map[i][q]);
			else if (map[i][q] == '1')
				printf("\e[0;30m%c\e[1;32m", map[i][q]);
			else
				printf("\e[1;36m%c\e[1;32m", map[i][q]);
			q++;
		}
		printf("\n");
		i++;
	}
}
