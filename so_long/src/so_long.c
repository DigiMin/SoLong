/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 10:39:17 by honnguye         ###   ########.fr       */
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

	if (argc != 2 || ft_check_extension(argv[1]) != SUCCESS)
	{
		ft_printf("Usage: %s <map.ber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (ft_init_graphics(&graphics, argv[1]) != SUCCESS)
	{
		mlx_terminate(graphics.mlx);
		return (EXIT_SUCCESS);
	}
	ft_printf("GRAPHICS INITIALIZED\n");
	mlx_loop_hook(graphics.mlx, ft_hook, &graphics);
	mlx_loop(graphics.mlx);
	mlx_terminate(graphics.mlx);
	return (EXIT_SUCCESS);
}

// TODO: FREEEEEEEEEEEEEEEEEE
// TODO: better error handling
// TODO: check this function mlx_close_window(mlx_t* mlx)
// mlx_delete_image(mlx, img);
// TODO: MAXIMUM MOVEMENT ENDING GAME
// TODO: figure out the segfaultfor the toobig map
// TODO: MAKEFILE erase object files after making and download and install mlx in the makefile
// return (0);