/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 11:09:10 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// -----------------------------------------------------------------------------

int32_t	main(int argc, char **argv)
{
	t_graphics	graphics;
	t_graphics	*graphics_ptr;
	t_error		ret;

	if (argc != 2)
	{
		ret = WRONG_ARGS;
		ft_printf("%s\n", ft_error_str(ret));
		return (ret);
	}
	ret = ft_check_extension(argv[1]);
	if (ret != SUCCESS)
	{
		ft_printf("%s\n", ft_error_str(ret));
		return (ret);
	}
	graphics_ptr = &graphics;
	if (ft_init_graphics(&graphics_ptr, argv[1]) != SUCCESS)
		return (EXIT_FAILURE);
	mlx_loop_hook(graphics.mlx, ft_hook, &graphics);
	mlx_loop(graphics.mlx);
	ft_error(&graphics_ptr, SUCCESS);
}

// TODO: MAKEFILE erase object files after
// making and download and install mlx in the makefile
// TODO: WIN AND FAIL OVER COUNTER
// TODO: Change tower when everything is collected