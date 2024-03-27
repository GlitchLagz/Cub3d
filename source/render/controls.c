/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:25:33 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/22 14:17:31 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	key_press(int key, t_program *pro)
{
	if (key == 0)
		pro->a = 1;
	if (key == 2)
		pro->d = 1;
	if (key == 13)
		pro->w = 1;
	if (key == 1)
		pro->s = 1;
	if (key == 123)
		pro->left = 1;
	if (key == 124)
		pro->right = 1;
	if (key == 53)
		exit_program(0, pro);
	return (0);
}

static int	key_release(int key, t_program *pro)
{
	if (key == 0)
		pro->a = 0;
	if (key == 2)
		pro->d = 0;
	if (key == 13)
		pro->w = 0;
	if (key == 1)
		pro->s = 0;
	if (key == 123)
		pro->left = 0;
	if (key == 124)
		pro->right = 0;
	return (0);
}

static int	x_close(t_program *pro)
{
	exit_program(0, pro);
	return (1);
}

int	mouse(int x, int y, t_program *pro)
{
	(void)y;
	if (x > pro->mousex)
	{
		pro->pa += 0.04;
		if (pro->pa > 2 * PI)
			pro->pa -= 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	else if (x < pro->mousex)
	{
		pro->pa -= 0.04;
		if (pro->pa < 0)
			pro->pa += 2 * PI;
		pro->pdx = cos(pro->pa) * 5;
		pro->pdy = sin(pro->pa) * 5;
	}
	if (x > 2450 || x < -90)
		x = 1000;
	pro->mousex = x;
	return (0);
}

void	controls(t_program *pro)
{
	mlx_hook(pro->view->win, 2, 0, key_press, pro);
	mlx_hook(pro->view->win, 3, 0, key_release, pro);
	mlx_mouse_hide();
	mlx_hook(pro->view->win, 6, 0, &mouse, pro);
	mlx_hook(pro->view->win, 17, 0, x_close, pro);
}
