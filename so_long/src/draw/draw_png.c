/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:19:25 by mina              #+#    #+#             */
/*   Updated: 2025/01/21 10:03:04 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

mlx_image_t	*ft_draw_asset(t_graphics **graphics, mlx_t *mlx, char *path,
		t_coord *asset)
{
	mlx_image_t	*image;
	t_coord		*coord;
	int			ret;

	image = ft_load_png(graphics, mlx, path);
	coord = asset;
	while (coord != NULL)
	{
		ret = mlx_image_to_window(mlx, image, coord->x * image->width, coord->y
				* image->height);
		if (ret == -1)
			return (NULL);
		coord = coord->next;
	}
	return (image);
}

mlx_image_t	*ft_draw_exit(t_graphics **graphics, mlx_t *mlx, char *path,
		t_coord *asset)
{
	mlx_image_t	*image;
	t_coord		*coord;
	int			ret;

	image = ft_load_png(graphics, mlx, path);
	coord = asset;
	ret = mlx_image_to_window(mlx, image, coord->x * image->width, (coord->y
				* image->width) - image->width);
	if (ret == -1)
		return (NULL);
	return (image);
}

mlx_image_t	*ft_draw_number(t_graphics **graphics, char *path)
{
	mlx_image_t	*img;
	int			i;
	int			x;
	int			ret;

	img = ft_load_png(graphics, (*graphics)->mlx, path);
	x = ((*graphics)->map->width - 3) * 64;
	i = 0;
	while (i < 6)
	{
		ret = mlx_image_to_window((*graphics)->mlx, img, x, 0);
		if (ret == -1)
			return (NULL);
		x += HALF_SIZE;
		i++;
	}
	return (img);
}

mlx_image_t	*ft_load_png(t_graphics **graphics, mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		ft_mlx_error(graphics, MLX_DRAW_FAILURE);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_mlx_error(graphics, MLX_DRAW_FAILURE);
	return (image);
}
