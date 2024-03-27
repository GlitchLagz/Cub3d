/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:09:43 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 12:42:49 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H

typedef float			t_f32;
typedef unsigned char	t_rgb;
typedef unsigned int	t_u32;
typedef int				t_fd;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	short	resolution[2];
}	t_mlx;

typedef struct s_world
{
	int		c_color[3];
	int		f_color[3];
	char	*north_texture_path;
	char	*south_texture_path;
	char	*east_texture_path;
	char	*west_texture_path;
}	t_world;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp; // bits per pixel
	int		endian;
	int		line_size;
	int		width;
	int		height;	
}	t_image;

typedef struct s_cpy
{
	int			x; // x player
	int			y; // y player
	int			i;
	int			mx; // mapx
	int			my; // mapy
	int			mp; //map itererator
	int			dof; //depth of field
	int			dist; // final distance, the shorter distance of Vert and Horiz
	int			disl;
	int			disr;
	int			disb;
	int			disfl;
	int			disfr;
	int			disbl;
	int			disbr;
	float		pdx; //player delta x
	float		pdy; //player delta y
	float		pa; // player angle
	float		dish; //horiz distance to compare to disV
	float		disv; //vert distance tp compare to disH
	float		hx; //horiz x
	float		hy; //horiz y
	float		lineh; // line height for 3d world
	float		lineo; // line offset to focus window
	float		ca; // cosine angle to fix fish eye
	float		rx; // ray x
	float		ry; // ray y
	float		ra; // ray angle
	float		xo; // x offset
	float		yo; // y offset
	float		vx; // vertical x
	float		vy; // vertical y
}	t_cpy;

typedef struct s_program
{
	t_mlx		*view;
	t_world		*world;
	t_fd		map_file;
	t_image		textures[4];
	t_image		render_texture;
	char		**map;
	int			*maptest;
	char		**map_c;
	int			map_i;
	int			lines;
	int			p_x;
	int			p_y;
	int			p256;
	int			floor_c;
	int			ceiling_c;
	int			mapx;
	int			mapy;
	int			map_s;
	int			map_array_len;
	int			width_units;
	int			height_units;
	int			x; // x player
	int			y; // y player
	int			i;
	int			k;
	int			ii;
	int			len;
	int			mx; // mapx
	int			my; // mapy
	int			mp; //map itererator
	int			dof; //depth of field
	float		dist; // final distance, the shorter distance of Vert and Horiz
	int			disl;
	int			disr;
	int			disb;
	int			disfl;
	int			disfr;
	int			disbl;
	int			disbr;
	int			w;
	int			s;
	int			a;
	int			d;
	int			right;
	int			left;
	int			mousex;
	float		pdx; //player delta x
	float		pdy; //player delta y
	float		pa; // player angle
	float		dish; //horiz distance to compare to disV
	float		disv; //vert distance tp compare to disH
	float		hx; //horiz x
	float		hy; //horiz y
	float		lineh; // line height for 3d world
	float		lineo; // line offset to focus window
	float		ca; // cosine angle to fix fish eye
	float		rx; // ray x
	float		ry; // ray y
	float		ra; // ray angle
	float		xo; // x offset
	float		yo; // y offset
	float		vx; // vertical x
	float		vy; // vertical y
}	t_program;
#endif