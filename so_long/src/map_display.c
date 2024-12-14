/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:25 by mina              #+#    #+#             */
/*   Updated: 2024/12/12 13:37:20 by mina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void    ft_load_to_mlx(mlx_t *mlx, mlx_image_t *image, t_coord *coord, char *path)
{
	mlx_texture_t* texture = mlx_load_png(path);
    mlx_image_t *image;
    
	if (!texture)
	{
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
        return (NULL);
	}

	// Convert texture to a displayable image
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
        return (NULL);
	}
    
    // Display the image
	if (mlx_image_to_window(mlx, image, coord->x, coord->y) < 0)
	{
        // free
        return ;
	}
    
}

void    ft_draw_map(t_map *map)
{
    
    
    
// }

