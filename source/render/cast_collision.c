/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:08:27 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 11:20:05 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cpy_back_two(t_program *pro, t_cpy cpy)
{
	pro->mp = cpy.mp;
	pro->my = cpy.my;
	pro->mx = cpy.mx;
	pro->disb = cpy.disb;
	pro->disl = cpy.disl;
	pro->disr = cpy.disr;
	pro->disbl = cpy.disbl;
	pro->disfl = cpy.disfl;
	pro->disbr = cpy.disbr;
	pro->disfr = cpy.disfr;
	pro->pa = cpy.pa;
}

void	cpy_back(t_program *pro, t_cpy cpy)
{
	pro->x = cpy.x;
	pro->y = cpy.y;
	pro->ra = cpy.ra;
	pro->xo = cpy.xo;
	pro->yo = cpy.yo;
	pro->ry = cpy.ry;
	pro->rx = cpy.rx;
	pro->dof = cpy.dof;
	pro->hx = cpy.hx;
	pro->hy = cpy.hy;
	pro->vx = cpy.vx;
	pro->vy = cpy.vy;
	pro->dish = cpy.dish;
	pro->disv = cpy.disv;
	pro->dist = cpy.dist;
	cpy_back_two(pro, cpy);
}

t_cpy	light_cpy(t_program *pro)
{
	t_cpy	cpy;

	cpy.x = pro->x;
	cpy.y = pro->y;
	cpy.ra = pro->ra;
	cpy.xo = pro->xo;
	cpy.yo = pro->yo;
	cpy.ry = pro->ry;
	cpy.rx = pro->rx;
	cpy.dof = pro->dof;
	cpy.hx = pro->hx;
	cpy.hy = pro->hy;
	cpy.vx = pro->vx;
	cpy.vy = pro->vy;
	cpy.dish = pro->dish;
	cpy.disv = pro->disv;
	cpy.dist = pro->dist;
	cpy.mp = pro->mp;
	cpy.my = pro->my;
	cpy.mx = pro->mx;
	cpy.pa = pro->pa;
	return (cpy);
}

void	cast_collision_two(t_program *pro)
{
	calc_horiz(pro);
	calc_horiz_two(pro);
	calc_vert(pro);
	calc_vert_two(pro);
	set_dist(pro);
}

void	cast_collision(t_program *pro)
{
	int		i;
	t_cpy	cpy;

	cpy = light_cpy(pro);
	i = -1;
	while (++i != 7)
	{
		pro->ra = reset_ra(pro->ra + (DR * 45));
		cast_collision_two(pro);
		if (i == 0)
			cpy.disfr = pro->dist;
		if (i == 1)
			cpy.disr = pro->dist;
		if (i == 2)
			cpy.disbr = pro->dist;
		if (i == 3)
			cpy.disb = pro->dist;
		if (i == 4)
			cpy.disbl = pro->dist;
		if (i == 5)
			cpy.disl = pro->dist;
		if (i == 6)
			cpy.disfl = pro->dist;
	}
	cpy_back(pro, cpy);
}
