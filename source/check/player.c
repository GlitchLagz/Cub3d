/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:09:47 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:48 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	config_direction(t_program *pro, char c)
{
	if (c == 'N')
	{
		pro->pa -= P2;
		if (pro->pa < 0)
			pro->pa += 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	if (c == 'S')
	{
		pro->pa += P2;
		if (pro->pa < 0)
			pro->pa += 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	if (c == 'E')
		return ;
	if (c == 'W')
		setw(pro);
}

void	setw(t_program *pro)
{
	pro->pa += PI;
	if (pro->pa < 0)
		pro->pa += 2 * PI;
	pro->pdx = cos(pro->pa) * 5;
	pro->pdy = sin(pro->pa) * 5;
}

void	find_player(t_program *pro)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (pro->map[i])
	{
		j = 0;
		while (pro->map[i][j])
		{
			if (is_player(pro->map[i][j]))
			{
				player_count++;
				pro->x = j;
				pro->y = i;
				config_direction(pro, pro->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (player_count > 1)
		error_exit("Too Many Player Characters On Map!",
			PARSE_ERROR, pro);
}
