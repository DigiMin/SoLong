/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:25 by mina              #+#    #+#             */
/*   Updated: 2024/12/14 11:48:52 by mina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

mlx_image_t    *ft_load_png(mlx_t *mlx, char *path);

void    ft_draw_map(mlx_t *mlx, t_map *map)
{
    mlx_image_t *image = ft_load_png(mlx, "./graphicsTinySwords/Terrain/Water/Water.png");
	t_coord *coord = map->walls;
	// Display the image
	while (coord->next!= NULL)
	{
		if (mlx_image_to_window(mlx, image, coord->x, coord->y) < 0)
		{
			// free
			return ;
		}
		coord = coord->next;
	}
	if (mlx_image_to_window(mlx, image, coord->x, coord->y) < 0)
	{
		// free
		return ;
	}
}

void	ft_for_each_coord()
{
	
}

char	*ft_get_png_path(char asset)
{
	if (asset == 'w')
		return ("./graphicsTinySwords/Terrain/Water/Water.png");
}


mlx_image_t    *ft_load_png(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
    mlx_image_t		*image;
    
	texture = mlx_load_png(path);
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
    return (image);
}