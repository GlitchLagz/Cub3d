/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:52:13 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/26 12:25:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_exit(char *mess, int error_type, t_program *pro)
{
	printf("\e[1;31mError; Explicit: %s\n", mess);
	exit_program(error_type, pro);
}

void	exit_program(int error_type, t_program *pro)
{
	close(pro->map_file);
	free_program(pro);
	printf("codename: --___-- has exited with an error code <%d>\n",
		error_type);
	printf("\e[0;32m");
	exit(error_type);
}
