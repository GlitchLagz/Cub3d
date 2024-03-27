/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:23:04 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:26:17 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_program(t_program *pro)
{
	if (pro->view)
		free_view(pro);
	if (pro->world)
		free_world(pro);
	if (pro->map && pro->map[0])
		free_2d_char(pro->map, ft_lstlen(pro->map));
	if (pro->map_c)
		free_2d_char(pro->map_c, ft_lstlen(pro->map_c));
	if (pro->maptest)
		free(pro->maptest);
	if (pro)
		free(pro);
}

void	free_2d_char(char **f, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(f[i++]);
	free(f);
}

void	free_view(t_program *pro)
{
	if (pro->textures[0].img)
		mlx_destroy_image(pro->view->mlx, pro->textures[0].img);
	if (pro->textures[1].img)
		mlx_destroy_image(pro->view->mlx, pro->textures[1].img);
	if (pro->textures[2].img)
		mlx_destroy_image(pro->view->mlx, pro->textures[2].img);
	if (pro->textures[3].img)
		mlx_destroy_image(pro->view->mlx, pro->textures[3].img);
	if (pro->render_texture.img)
		mlx_destroy_image(pro->view->mlx, pro->render_texture.img);
	if (pro->view->win)
		mlx_destroy_window(pro->view->mlx, pro->view->win);
	if (pro->view)
		free(pro->view);
}

void	free_world(t_program *pro)
{
	if (pro->world->south_texture_path)
		free(pro->world->south_texture_path);
	if (pro->world->west_texture_path)
		free(pro->world->west_texture_path);
	if (pro->world->east_texture_path)
		free(pro->world->east_texture_path);
	if (pro->world->north_texture_path)
		free(pro->world->north_texture_path);
	if (pro->world)
		free(pro->world);
}
