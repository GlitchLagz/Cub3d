/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:03:26 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 11:01:57 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	player_dir(t_program *pro)
{
	if (pro->disv > pro->dish)
		return (pro->ra > 0 && pro->ra < PI);
	if (pro->disv < pro->dish)
		return ((pro->ra < PI + P2 && pro->ra > P2) + 2);
	return (0);
}

//colour = (int)((j / pro->lineH) * 255) << 16 | 
//((int)(x * 255) << 8); //gradient
// ++l < 1024/128 res by rays

void	draw_vert(t_program *pro, int r)
{
	int		j;
	int		l;
	int		dir;
	float	x;
	int		colour;

	x = pro->rx / 128.0;
	if (pro->disv < pro->dish)
		x = pro->ry / 128.0;
	x -= floor(x);
	j = -1;
	while (++j < pro->lineh)
	{
		l = -1;
		dir = player_dir(pro);
		colour = pixel_get(&pro->textures[dir], x * pro->textures[dir].width,
				(j / pro->lineh) * pro->textures[dir].height);
		while (++l < 8)
			pixel_set(&pro->render_texture, r * 8 + l, pro->lineo + j, colour);
	}
}

int	int_convert(t_program *pro, int nb)
{
	if (nb == 0)
		return (pro->world->c_color[X] << 16 | pro->world->c_color[Y] << 8
			| pro->world->c_color[Z]);
	else
		return (pro->world->f_color[X] << 16 | pro->world->f_color[Y] << 8
			| pro->world->f_color[Z]);
}

void	draw_background(t_image *img, t_program *pro)
{
	int	x;
	int	y;
	int	colour;

	y = -1;
	pro->p_x = 0;
	colour = int_convert(pro, 0);
	while (++y < (img->height / 2))
	{
		x = -1;
		while (++x < img->width)
			pixel_set(img, x, y, colour);
	}
	colour = int_convert(pro, 1);
	while (++y < (img->height))
	{
		x = -1;
		while (++x < img->width)
			pixel_set(img, x, y, colour);
	}
}

//64 == cube size, 640 is window height
void	draw_3d(t_program *pro)
{
	pro->ca = pro->ra - pro->pa;
	if (pro->ca < 0)
		pro->ca += 2 * PI;
	if (pro->ca > 2 * PI)
		pro->ca -= 2 * PI;
	pro->dist *= cos(pro->ca);
	pro->lineh = (64.0 / pro->dist) * RES_DEFAULT_X / 2.0;
	if (pro->lineh > RES_DEFAULT_Y * 8)
		pro->lineh = RES_DEFAULT_Y * 8;
	pro->lineo = (RES_DEFAULT_Y / 2) - (pro->lineh / 2);
}
