/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:20:55 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:24:53 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i + 1);
}

int	init_program(t_program *pro, char *filename)
{
	pro->map_i = 0;
	pro->p256 = 256;
	pro->map_file = open(filename, O_RDONLY);
	pro->lines = ft_lines(pro->map_file);
	pro->map_file = open(filename, O_RDONLY);
	pro->map = malloc(sizeof(char *) * pro->lines);
	pro->map[0] = NULL;
	if (!pro->map_file)
	{
		printf("File did not open.\n");
		error_exit("read permission?\n", MEMORY_ALLOCATION_ERROR, pro);
	}
	pro->world = malloc(sizeof(t_world));
	pro->view = malloc(sizeof(t_world));
	if (!pro->world || !pro->view)
	{
		printf("Weird... your computer doesnt remember...\n");
		error_exit("exiting\n", MEMORY_ALLOCATION_ERROR, pro);
	}
	init_view(pro->view, pro);
	init_world(pro->world, pro);
	return (1);
}

void	init_view(t_mlx *view, t_program *pro)
{
	view->mlx = mlx_init();
	printf("mlx:%p\n", view->mlx);
	if (!view->mlx)
	{
		printf("Weird... your computer doesnt remember...");
		error_exit("lost the root? ... library\n",
			MEMORY_ALLOCATION_ERROR, pro);
	}
	view->win = NULL;
	return ;
}

void	init_world(t_world *world, t_program *pro)
{
	world->c_color[X] = COLOUR_DEFAULT;
	world->c_color[Y] = COLOUR_DEFAULT;
	world->c_color[Z] = COLOUR_DEFAULT;
	world->f_color[X] = COLOUR_DEFAULT;
	world->f_color[Y] = COLOUR_DEFAULT;
	world->f_color[Z] = COLOUR_DEFAULT;
	pro->world->north_texture_path = NULL;
	pro->world->south_texture_path = NULL;
	pro->world->east_texture_path = NULL;
	pro->world->west_texture_path = NULL;
	return ;
}

void	read_textures(t_program *pro)
{
	if (pro->world->north_texture_path)
		pro->textures[0] = image_load(pro->view->mlx,
				pro->world->north_texture_path);
	if (pro->world->south_texture_path)
		pro->textures[1] = image_load(pro->view->mlx,
				pro->world->south_texture_path);
	if (pro->world->east_texture_path)
		pro->textures[2] = image_load(pro->view->mlx,
				pro->world->east_texture_path);
	if (pro->world->west_texture_path)
		pro->textures[3] = image_load(pro->view->mlx,
				pro->world->west_texture_path);
}
