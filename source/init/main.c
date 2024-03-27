/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:49:48 by dhadding          #+#    #+#             */
/*   Updated: 2024/03/20 15:46:41 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_program	*pro;

	pro = malloc(sizeof(t_program));
	*pro = (t_program){0};
	if (argc == ONE_PARAMETER)
		error_exit("Include map path as the second parameter;",
			ONE_PARAMETER, pro);
	else if (argc == TWO_PARAMETER)
	{
		init_program(pro, argv[1]);
		parse_parameters(pro);
		render_world(pro);
	}
	else
		error_exit("Too Many Parameters!\n",
			ERROR, pro);
	return (MEMORY_ALLOCATION_ERROR);
}
