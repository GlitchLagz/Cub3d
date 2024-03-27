/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:35:08 by tpawson           #+#    #+#             */
/*   Updated: 2024/03/26 12:47:05 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_num(char c, t_program *pro)
{
	if (c == '-')
		error_exit("RGB Configuration: NO NEGATIVE VALUES)\n",
			PARSE_ERROR, pro);
	if (c == '0' || c == '1' || c == '2' || c == '3'
		|| c == '4' || c == '5' || c == '6' || c == '7'
		|| c == '8' || c == '9')
		return (1);
	return (0);
}

void	c_color_two(char *line, int i, t_program *pro, char *str)
{
	int	k;

	k = 0;
	if (line[i] == ',')
	{
		while (!valid_num(line[i], pro) && line[i])
			i++;
		if (line[i] == '\n' || line[i] == '\0'
			|| line[i] == ' ' || line[i] == '\t')
			error_exit("RGB Configuration (MISSING VALUE)\n",
				PARSE_ERROR, pro);
		while (valid_num(line[i], pro) && line[i])
			str[k++] = line[i++];
		pro->world->c_color[Z] = ft_atoi(str);
	}
	else
		error_exit("RGB Configuration ( ',' Between Values )\n",
			PARSE_ERROR, pro);
	i = -1;
	while (++i < 3)
		if (pro->world->f_color[i] < 0 || pro->world->f_color[i] > 255)
			error_exit("RGB Value Range ( 0 - 255 )\n", PARSE_ERROR, pro);
}

void	c_color_rgb_value(char *line, t_program *pro)
{
	char	*str;

	pro->ii = 1;
	pro->k = 0;
	str = malloc(sizeof(char) * ft_strlen(line));
	while (!valid_num(line[pro->ii], pro) && line[pro->ii])
		pro->ii++;
	if (line[pro->ii] != '\n' && line[pro->ii] != '\0')
		while (valid_num(line[pro->ii], pro) && line[pro->ii])
			str[pro->k++] = line[pro->ii++];
	pro->world->c_color[X] = ft_atoi(str);
	pro->k = 0;
	if (line[pro->ii] == ',')
	{
		while (!valid_num(line[pro->ii], pro) && line[pro->ii])
			pro->ii++;
		while (valid_num(line[pro->ii], pro) && line[pro->i])
			str[pro->k++] = line[pro->ii++];
		pro->world->c_color[Y] = ft_atoi(str);
	}
	else
		error_exit("RGB Configuration ( ',' Between Values )\n",
			PARSE_ERROR, pro);
	c_color_two(line, pro->ii, pro, str);
	free(str);
}

void	f_color_two(char *line, int i, t_program *pro, char *str)
{
	int	k;

	k = 0;
	if (line[i] == ',')
	{
		while (!valid_num(line[i], pro) && line[i])
			i++;
		if (line[i] == '\n' || line[i] == '\0'
			|| line[i] == ' ' || line[i] == '\t')
			error_exit("RGB Configuration (MISSING VALUE)\n",
				PARSE_ERROR, pro);
		while (valid_num(line[i], pro) && line[i])
			str[k++] = line[i++];
		pro->world->f_color[Z] = ft_atoi(str);
	}
	else
		error_exit("RGB Configuration ( ',' Between Values )\n",
			PARSE_ERROR, pro);
	i = -1;
	printf("%d\n", pro->world->f_color[Z]);
	while (++i < 3)
		if (pro->world->f_color[i] < 0 || pro->world->f_color[i] > 255)
			error_exit("RGB Value Range ( 0 - 255 )\n", PARSE_ERROR, pro);
}

void	f_color_rgb_value(char *line, t_program *pro)
{
	char	*str;

	pro->ii = 1;
	pro->k = 0;
	str = malloc(sizeof(char) * ft_strlen(line));
	while (!valid_num(line[pro->ii], pro) && line[pro->ii])
		pro->ii++;
	if (line[pro->ii] != '\n' && line[pro->ii] != '\0')
		while (valid_num(line[pro->ii], pro) && line[pro->ii])
			str[pro->k++] = line[pro->ii++];
	pro->world->f_color[X] = ft_atoi(str);
	pro->k = 0;
	if (line[pro->ii] == ',')
	{
		while (!valid_num(line[pro->ii], pro) && line[pro->ii])
			pro->ii++;
		while (valid_num(line[pro->ii], pro) && line[pro->ii])
			str[pro->k++] = line[pro->ii++];
		pro->world->f_color[Y] = ft_atoi(str);
	}
	else
		error_exit("RGB Configuration ( ',' Between Values )\n",
			PARSE_ERROR, pro);
	f_color_two(line, pro->ii, pro, str);
	free(str);
}
