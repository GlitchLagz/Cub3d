/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:41:11 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/18 13:05:25 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INIT_H
# define CUB3D_INIT_H

// EXIT.C //
void	error_exit(char *mess, int error_type, t_program *pro);
void	exit_program(int error_type, t_program *pro);

// FREE?.C //
void	free_program(t_program *pro);
void	free_view(t_program *pro);
void	free_world(t_program *pro);
void	free_2d_char(char **f, int len);

// INIT.C //
int		init_program(t_program *pro, char *filename);
void	init_view(t_mlx *view, t_program *pro);
void	init_world(t_world *world, t_program *pro);
void	read_textures(t_program *pro);
void	*read_texture(char *filename, t_program *pro);

#endif