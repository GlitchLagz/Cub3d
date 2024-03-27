/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:07:07 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 11:02:57 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	look(t_program *pro)
{
	if (pro->left)
	{
		pro->pa -= 0.1;
		if (pro->pa < 0)
			pro->pa += 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	if (pro->right)
	{
		pro->pa += 0.1;
		if (pro->pa > 2 * PI)
			pro->pa -= 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	return (0);
}

int	wall_bool(t_program *pro)
{
	if (pro->dist > 13 && pro->w && pro->disfl > 13 && pro->disfr > 13)
		return (1);
	if (pro->disr > 13 && pro->d && pro->disbl > 13 && pro->disbr
		> 13 && pro->disfl > 13 && pro->disfr > 13)
		return (1);
	if (pro->disl > 13 && pro->a && pro->disfl > 13 && pro->disfr
		> 13 && pro->disbl > 13 && pro->disbr > 13)
		return (1);
	if (pro->disb > 13 && pro->s && pro->disbl > 13 && pro->disbr > 13)
		return (1);
	return (0);
}

void	movement(t_program *pro)
{
	int	check;

	check = wall_bool(pro);
	if (pro->s && check)
	{
		pro->y -= pro->pdy;
		pro->x -= pro->pdx;
	}
	if (pro->w && check)
	{
		pro->y += pro->pdy;
		pro->x += pro->pdx;
	}
	if (pro->d && check)
	{
		pro->x -= pro->pdy;
		pro->y += pro->pdx;
	}
	if (pro->a && check)
	{
		pro->x += pro->pdy;
		pro->y -= pro->pdx;
	}
	if ((pro->left || pro->right))
		look(pro);
}
