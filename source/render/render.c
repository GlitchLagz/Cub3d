/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:13:02 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 13:08:33 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

// fov 128/2 == 64 (incrementing by half a degree)
void	draw_rays(t_program *pro)
{
	int	r;

	image_clear(&pro->render_texture, 0);
	draw_background(&pro->render_texture, pro);
	pro->ra = reset_ra(pro->pa - DR * 30);
	r = 0;
	while (r < 128)
	{
		calc_horiz(pro);
		calc_horiz_two(pro);
		calc_vert(pro);
		calc_vert_two(pro);
		set_dist(pro);
		if (r == 64)
			cast_collision(pro);
		draw_3d(pro);
		draw_vert(pro, r);
		pro->ra = reset_ra(pro->ra + DR / 2);
		r++;
	}
	mlx_put_image_to_window(pro->view->mlx, pro->view->win,
		pro->render_texture.img, 0, 0);
}

int	frame_gen(t_program *pro)
{
	mlx_clear_window(pro->view->mlx, pro->view->win);
	draw_rays(pro);
	movement(pro);
	return (0);
}

int	render_world(t_program *pro)
{
	pro->x *= 64;
	pro->y *= 64;
	pro->x += 32;
	pro->y += 32;
	pro->maptest = map_convert(pro->map, pro);
	pro->view->win = mlx_new_window(pro->view->mlx,
			RES_DEFAULT_X, RES_DEFAULT_Y, "cub3D");
	pro->render_texture = image_new(pro->view->mlx,
			RES_DEFAULT_X, RES_DEFAULT_Y);
	read_textures(pro);
	controls(pro);
	mlx_loop_hook(pro->view->mlx, frame_gen, pro);
	mlx_loop(pro->view->mlx);
	return (0);
}
