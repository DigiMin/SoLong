/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/15 23:58:58 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// -----------------------------------------------------------------------------

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_graphics	graphics;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_init_graphics(&graphics, argv[1]);
	mlx_loop_hook(graphics.mlx, ft_hook, &graphics);
	mlx_loop(graphics.mlx);
	mlx_terminate(graphics.mlx);
	return (EXIT_SUCCESS);
}

	// TODO: FREEEEEEEEEEEEEEEEEE
	// TODO: use ft_printf to print the moves
	// TODO: refactor the code
	// TODO: better error handling
	// TODO: declare sturctures not pointers to them!!!
	// TODO: use int_32t instead of int
	// TODO: check this function mlx_close_window(mlx_t* mlx)
	//	/ mlx_delete_image(mlx, img);
	// // Optional, terminate will clean up any leftovers,
	//	this is just to demonstrate.
	// mlx_delete_texture(texture);
	// TODO: MAXIMUM MOVEMENT ENDING GAME
	// return (0);