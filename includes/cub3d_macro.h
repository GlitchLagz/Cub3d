/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:31:01 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 10:45:56 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_H
# define CUB3D_MACRO_H

# define SUCCESS 0
# define EPSILON 0.0001

// NAMES //
# define COMMENT "//"
# define FILE_PARAMETER
# define NORTH 0
# define NORTH_TEXTURE "NO"
# define SOUTH 1
# define SOUTH_TEXTURE "SO"
# define EAST 2
# define EAST_TEXTURE "EA"
# define WEST 3
# define WEST_TEXTURE "WE"
# define MAP 5
# define C_COLOR "C"
# define F_COLOR "F"
# define ONE_PARAMETER 1
# define TWO_PARAMETER 2
# define RES_DEFAULT_X 1024
# define RES_DEFAULT_Y 768
# define X 0
# define Y 1
# define Z 2
# define R 0
# define G 1
# define B 2
# define COLOUR_DEFAULT 128
# define EMPTY_LINE 11
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC_KEY 53
# define PI 3.1415926535
# define P2 1.57079632675
# define P3 4.71238898025

# define DR 0.0174533 //one degree in radians

// ERROR CODES //
# define ERROR -1
# define INIT_ERROR 5
# define PARSE_ERROR 6
# define RENDER_ERROR 7
# define MEMORY_ALLOCATION_ERROR 555

#endif