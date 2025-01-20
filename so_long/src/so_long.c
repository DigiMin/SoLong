/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:43 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// -----------------------------------------------------------------------------

int32_t	main(int argc, char **argv)
{
	t_graphics	graphics;
	t_graphics	*graphics_ptr;
	int			ret;

	if (argc != 2 || ft_check_extension(argv[1]) != SUCCESS)
	{
		ft_printf("Usage: %s <map.ber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	graphics_ptr = &graphics;
	ret = ft_init_graphics(&graphics_ptr, argv[1]);
	if (ret != SUCCESS)
		return (EXIT_FAILURE);
	printf("GRAPHICS INITIALIZED\n");
	mlx_loop_hook(graphics.mlx, ft_hook, &graphics);
	mlx_loop(graphics.mlx);
	ft_free_graphics(&graphics_ptr);
	return (EXIT_SUCCESS);
}

// TODO: FREEEEEEEEEEEEEEEEEE
// TODO: MAXIMUM MOVEMENT ENDING GAME
// TODO: better error handling
// TODO: figure out the segfaultfor the toobig map
// TODO: check this function mlx_close_window(mlx_t* mlx)
// mlx_delete_image(mlx, img);
// TODO: MAKEFILE erase object files after making and download and install mlx in the makefile
// TODO: WIN AND FAIL OVER COUNTER
// TODO: Change tower when everything is collected
// return (0);