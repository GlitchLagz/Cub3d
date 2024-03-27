/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast-setconditions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:08:35 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/18 11:54:04 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	reset_ra(float degree)
{
	if (degree < 0)
		degree += 2 * PI;
	if (degree > 2 * PI)
		degree -= 2 * PI;
	return (degree);
}

t_program	*set_values(t_program *pro, int nb)
{
	if (nb == 0)
	{
		pro->dof = 0;
		pro->dish = 1000000;
		pro->hx = pro->x;
		pro->hy = pro->y;
	}
	else if (nb == 1)
	{
		pro->dof = 0;
		pro->disv = 1000000;
		pro->vx = pro->x;
		pro->vy = pro->y;
	}
	return (pro);
}

void	set_dist(t_program *pro)
{
	if (pro->disv < pro->dish)
	{
		pro->rx = pro->vx;
		pro->ry = pro->vy;
		pro->dist = pro->disv;
	}
	if (pro->dish < pro->disv)
	{
		pro->rx = pro->hx;
		pro->ry = pro->hy;
		pro->dist = pro->dish;
	}
}
