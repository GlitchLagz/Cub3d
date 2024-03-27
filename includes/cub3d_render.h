/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:30:32 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:58:47 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H

// RENDER.H //
int			render_world(t_program *pro);

// rc-horizontal //
float		distance(float ax, float ay, float bx, float by);

void		calc_horiz(t_program *pro);
void		calc_horiz_two(t_program *pro);

// rc-vertical // 
void		calc_vert(t_program *pro);
void		calc_vert_two(t_program *pro);

// rc-setconditions //
float		reset_ra(float degree);
void		set_dist(t_program *pro);
t_program	*set_values(t_program *pro, int nb);

// controls //
void		controls(t_program *pro);
void		movement(t_program *pro);

// controls_two //

int			look(t_program *pro);

// render-utils //
int			*map_convert(char **map, t_program *pro);

// draw_functions //
void		draw_vert(t_program *pro, int r);
void		draw_3d(t_program *pro);
int			player_dir(t_program *pro);
void		draw_background(t_image *img, t_program *pro);

// cast_collision.c //

void		cast_collision(t_program *pro);

// better_mlx //
int			pixel_get(t_image *img, int x, int y);
void		pixel_set(t_image *img, int x, int y, int color);
t_image		image_load(void *mlx, char *path);
t_image		image_new(void *mlx, int width, int height);
void		image_clear(t_image *img, int colour);

#endif