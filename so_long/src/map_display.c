/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:25 by mina              #+#    #+#             */
/*   Updated: 2024/12/15 11:39:21 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// static mlx_image_t    *ft_load_png(mlx_t *mlx, char *path);

void    ft_draw_map(mlx_t *mlx, t_map *map,char *path, t_coord *asset)
{
    mlx_image_t *image = ft_load_png(mlx, path);
	t_coord *coord = asset;
	// Display the image
	while (coord != NULL)
	{
		mlx_image_to_window(mlx, image, coord->x * image->width, coord->y * image->height);
		coord = coord->next;
	}
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