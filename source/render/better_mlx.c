/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:10:52 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/22 19:34:18 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	pixel_get(t_image *img, int x, int y)
{
	return (img->addr[x + y * img->width]);
}

void	pixel_set(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		img->addr[x + y * img->width] = color;
}

t_image	image_load(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (img.img != NULL)
		img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
				&img.line_size, &img.endian);
	else
	{
		printf("%s doesn't exist\n", path);
		exit(0);
	}
	return (img);
}

t_image	image_new(void *mlx, int width, int height)
{
	t_image	img;

	img.width = width;
	img.height = height;
	img.img = mlx_new_image(mlx, width, height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.line_size, &img.endian);
	return (img);
}

void	image_clear(t_image *img, int colour)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			pixel_set(img, x, y, colour);
	}
}
