/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:05:38 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:51 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CHECK_H
# define CUB3D_CHECK_H

// CHECK_PARAMETERS.C //

void	surround_map_sides(char **map);
void	check_map_parameter(t_program *pro);
void	check_surrounds_right(t_program *pro);
void	fill_the_floor(t_program *pro, int x, int y, char paint);
int		count_floor_tiles(char **map);

// PLAYER.C //
void	find_player(t_program *pro);
int		is_player(char c);
void	setw(t_program *pro);

// PRINT.C //
void	print_map(char **map);
void	print_int_map(int *map, t_program *pro);

#endif