/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:21:52 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 11:35:47 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_copy(t_program *pro, char *line)
{
	int	i;

	i = -1;
	pro->map[pro->map_i] = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[++i])
		pro->map[pro->map_i][i] = line[i];
	pro->map[pro->map_i][i] = 0;
	pro->map_i += 1;
}

int	parse_parameters(t_program *pro)
{
	char	*line;

	line = get_next_line(pro->map_file);
	while (line)
	{
		if (check_line(line, pro) == MAP)
			pro->map[pro->map_i++] = ft_strndup(line, ft_strlen(line));
		free(line);
		line = get_next_line(pro->map_file);
	}
	pro->map[pro->map_i] = NULL;
	check_map_parameter(pro);
	return (1);
}

char	*parse_texture_path(char *line, t_program *pro)
{
	char	*path;
	int		i1;
	int		i2;
	int		i3;

	i1 = 0;
	i2 = 0;
	while (line[i1] != '.')
		i1++;
	i3 = i1;
	while (line[i1] != '\n' && line[i1] != '\0')
	{
		i1++;
		i2++;
	}
	--i2;
	path = ft_strndup(&line[i3], i2 + 1);
	if (!path)
		error_exit("Path Memory Allocation Error\n",
			MEMORY_ALLOCATION_ERROR, pro);
	if (access(path, F_OK) == 0)
		return (path);
	error_exit("Texture File Path Incorrect\n", PARSE_ERROR, pro);
	return ("missing texture");
}

int	map_check(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '1')
		return (1);
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int	check_line(char *line, t_program *pro)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '	')
		i++;
	if ((ft_strncmp(line, COMMENT, 2)) == 0)
		return (EMPTY_LINE);
	else if ((ft_strncmp(line, NORTH_TEXTURE, 2)) == 0)
		pro->world->north_texture_path = parse_texture_path(line, pro);
	else if ((ft_strncmp(line, SOUTH_TEXTURE, 2)) == 0)
		pro->world->south_texture_path = parse_texture_path(line, pro);
	else if ((ft_strncmp(line, EAST_TEXTURE, 2)) == 0)
		pro->world->east_texture_path = parse_texture_path(line, pro);
	else if ((ft_strncmp(line, WEST_TEXTURE, 2)) == 0)
		pro->world->west_texture_path = parse_texture_path(line, pro);
	else if ((ft_strncmp(line, F_COLOR, 1)) == 0)
		f_color_rgb_value(&line[1], pro);
	else if ((ft_strncmp(line, C_COLOR, 1)) == 0)
		c_color_rgb_value(&line[1], pro);
	else if (map_check(line) == 1)
		return (MAP);
	return (EMPTY_LINE);
}
