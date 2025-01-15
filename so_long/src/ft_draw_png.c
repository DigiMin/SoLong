/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:25 by mina              #+#    #+#             */
/*   Updated: 2025/01/15 20:54:31 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// static mlx_image_t    *ft_load_png(mlx_t *mlx, char *path);

mlx_image_t	*ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset)
{
	mlx_image_t	*image;
	t_coord		*coord;

	image = ft_load_png(mlx, path);
	coord = asset;
	while (coord != NULL)
	{
		mlx_image_to_window(mlx, image, coord->x * image->width, coord->y
			* image->height);
		coord = coord->next;
	}
	return (image);
}

mlx_image_t	*ft_draw_exit(mlx_t *mlx, char *path, t_coord *asset)
{
	mlx_image_t	*image;
	t_coord		*coord;

	image = ft_load_png(mlx, path);
	coord = asset;
	mlx_image_to_window(mlx, image, coord->x * image->width, (coord->y
			* image->width) - image->width);
	return (image);
}

mlx_image_t	*ft_load_png(mlx_t *mlx, char *path)
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
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	return (image);
}
