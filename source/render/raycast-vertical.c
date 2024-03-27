/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast-vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:02:54 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/18 11:54:11 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_vert(t_program *pro)
{
	float	ntan;

	pro = set_values(pro, 1);
	ntan = -tan(pro->ra);
	if (pro->ra > P2 && pro->ra < P3)
	{
		pro->rx = (((int)pro->x / 64) * 64) - 0.0001;
		pro->ry = (pro->x - pro->rx) * ntan + pro->y;
		pro->xo = -64;
		pro->yo = -pro-> xo * ntan;
	}
	if (pro->ra < P2 || pro->ra > P3)
	{
		pro->rx = (((int)pro->x / 64) * 64) + 64;
		pro->ry = (pro->x - pro->rx) * ntan + pro->y;
		pro->xo = 64;
		pro->yo = -pro->xo * ntan;
	}
	if (pro->ra == 0 || pro->ra == (float)PI)
	{
		pro->rx = pro->x;
		pro->ry = pro->y;
		pro->dof = 25;
	}
}

void	calc_vert_two(t_program *pro)
{
	while (pro->dof < 25)
	{
		pro->mx = (int)(pro->rx) / 64;
		pro->my = (int)(pro->ry) / 64;
		pro->mp = pro->my * pro->mapx + pro->mx;
		if (pro->mp > 0 && pro->mp < pro->map_array_len
			&& pro->maptest[pro->mp] == 1)
		{
			pro->vx = pro->rx;
			pro->vy = pro->ry;
			pro->disv = distance(pro->x, pro->y, pro->vx, pro->vy);
			pro->dof = 25;
		}
		else
		{
			pro->rx += pro->xo;
			pro->ry += pro->yo;
			pro->dof += 1;
		}
	}
}
