/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:38:15 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 12:22:54 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_set_map_img(t_graphics **graphics, t_map *map)
{
	char	*water;
	char	*grass;
	char	*collectable;
	char	*tower;
	char	*enemy;

	water = "./graphics/Terrain/Water.png";
	grass = "./graphics/Terrain/Grass_full.png";
	collectable = "./graphics/Resources/Shroom.png";
	tower = "./graphics/Resources/Tower_Blue_64.png";
	enemy = "./graphics/Enemy/Enemy.png";
	(*graphics)->wall = ft_draw_asset((*graphics)->mlx, water, map->walls);
	(*graphics)->space = ft_draw_asset((*graphics)->mlx, grass, map->spaces);
	(*graphics)->collectable = ft_draw_asset((*graphics)->mlx, collectable,
			map->collectibles);
	(*graphics)->exit = ft_draw_exit((*graphics)->mlx, tower, map->exit);
	(*graphics)->enemy = ft_draw_asset((*graphics)->mlx, enemy,
			(*graphics)->map->enemy);
	if (!(*graphics)->wall || !(*graphics)->space || !(*graphics)->collectable
		|| !(*graphics)->exit || !(*graphics)->enemy)
		return (MLX_DRAW_FAILURE);
	return (SUCCESS);
}
