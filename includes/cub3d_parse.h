/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:30:45 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 11:47:11 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSE_H
# define CUB3D_PARSE_H

// PARSE.C //
int		parse_parameters(t_program *pro);
void	parse_c_color_rgb_value(char *line, t_program *pro);
void	parse_f_color_rgb_value(char *line, t_program *pro);
char	*parse_texture_path(char *line, t_program *pro);
int		check_line(char *line, t_program *pro);
int		map_check(char *line);
void	f_color_rgb_value(char *line, t_program *pro);
void	c_color_rgb_value(char *line, t_program *pro);

#endif