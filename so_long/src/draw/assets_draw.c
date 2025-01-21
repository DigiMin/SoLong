/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:38:15 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 12:20:13 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_set_map_img(t_graphics **graphics, t_map *map)
{
	(*graphics)->wall = ft_draw_asset(graphics, (*graphics)->mlx,
			"./graphics/Terrain/Water.png", map->walls);
	(*graphics)->space = ft_draw_asset(graphics, (*graphics)->mlx,
			"./graphics/Terrain/Grass_full.png", map->spaces);
	(*graphics)->collectable = ft_draw_asset(graphics, (*graphics)->mlx,
			"./graphics/Resources/Shroom.png", map->collectibles);
	(*graphics)->exit = ft_draw_exit(graphics, (*graphics)->mlx,
			"./graphics/Resources/Tower_Blue_64.png", map->exit);
	(*graphics)->exit_open = ft_draw_exit(graphics, (*graphics)->mlx,
			"./graphics/Resources/Tower_Blue_o.png", map->exit);
	(*graphics)->enemy = ft_draw_asset(graphics, (*graphics)->mlx,
			"./graphics/Enemy/Enemy.png", (*graphics)->map->enemy);
	(*graphics)->num_bckgrnd = ft_draw_bckgrnd(graphics, "./graphics/UI/cb0.png");
	if (!(*graphics)->wall || !(*graphics)->space || !(*graphics)->collectable
		|| !(*graphics)->exit || !(*graphics)->exit_open || !(*graphics)->enemy)
		ft_mlx_error(graphics, MLX_DRAW_FAILURE);
	(*graphics)->exit_open->enabled = 0;
}


mlx_image_t	*ft_draw_bckgrnd(t_graphics **graphics, char *path)
{
	int	x;
	int ret;
	mlx_image_t *img;

	img = ft_load_png(graphics, (*graphics)->mlx, path);
	x = ((*graphics)->map->width - 3) * 64;
	ret = mlx_image_to_window((*graphics)->mlx, img, x, 0);
	if (ret == -1)
		return (ft_mlx_error(graphics, MLX_DRAW_FAILURE), NULL);
	return (img);
}