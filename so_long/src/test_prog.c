/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/12 13:36:24 by mina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// // -----------------------------------------------------------------------------
// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

void ft_hook(void* param, mlx_image_t *image)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W) || mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D) || mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	mlx_image_t *image;
	mlx_t *mlx;
	t_map	*map;
	
	char *png = "./graphicsTinySwords/Resources/Resources/G_Idle.png";
	map = ft_map_validator();
	if (!map)
		printf("The map could not be used\n");
	else
		printf("The map is good as it is, YAY!\n");

	// Start mlx
	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
	{
		mlx_terminate(mlx);
        error();
	}

	printf("Hello");
	// Try to load the file
	mlx_texture_t* texture = mlx_load_png(png);
	if (!texture)
	{
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
        error();
	}

	// Convert texture to a displayable image
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
        error();
	}

	// Display the image
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
	{
		mlx_delete_texture(texture);
		mlx_terminate(mlx);		
		error();
	}

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}