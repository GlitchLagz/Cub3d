/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast-horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:10:15 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/18 11:51:55 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//pythag
float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	calc_horiz(t_program *pro)
{
	float	atan;

	atan = -1 / tan(pro->ra);
	pro = set_values(pro, 0);
	if (pro->ra > PI)
	{
		pro->ry = (((int)pro->y / 64) * 64) - 0.0001;
		pro->rx = (pro->y - pro->ry) * atan + pro->x;
		pro->yo = -64;
		pro->xo = -pro->yo * atan;
	}
	if (pro->ra < PI)
	{
		pro->ry = (((int)pro->y / 64) * 64) + 64;
		pro->rx = (pro->y - pro->ry) * atan + pro->x;
		pro->yo = 64;
		pro->xo = - (pro->yo * atan);
	}
	if (pro->ra == 0 || pro->ra == (float)PI)
	{
		pro->rx = pro->x;
		pro->ry = pro->y;
		pro->dof = 25;
	}
}

void	calc_horiz_two(t_program *pro)
{
	while (pro->dof < 25)
	{
		pro->mx = (int)(pro->rx) / 64;
		pro->my = (int)(pro->ry) / 64;
		pro->mp = (pro->my * pro->mapx) + pro->mx;
		if (pro->mp > 0 && pro->mp < pro->map_array_len
			&& pro->maptest[pro->mp] == 1)
		{
			pro->hx = pro->rx;
			pro->hy = pro->ry;
			pro->dish = distance(pro->x, pro->y, pro->hx, pro->hy);
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
