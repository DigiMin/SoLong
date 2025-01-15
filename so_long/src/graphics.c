/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/16 00:03:20 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_init_graphics(t_graphics *graphics, char *path)
{
	graphics->map = ft_init_map(path);
	if (!graphics->map)
		return (INIT_FAILED);
	if (ft_map_parser(graphics->map, path) != SUCCESS)
	{
		// ft_free_map(graphics->map->height, graphics->map);
		return (INIT_FAILED);
	}
	if (!graphics->map)
		printf("The map could not be used\n");
	else
		printf("The map is good as it is, YAY!\n");
	graphics->mlx = mlx_init(graphics->map->width * IMG_SIZE,
			graphics->map->height * IMG_SIZE, "Whole New World", false);
	if (!graphics->mlx)
	{
		mlx_terminate(graphics->mlx);
		error();
	}
	ft_set_map_img(graphics, graphics->map);
	graphics->anim = ft_init_game_anim(graphics);
	graphics->map->collected = 0;
	graphics->can_move = 1;
	graphics->last_anim_dir = PLAYER_MR;
	printf("EVERYTHING INITED\n");
	graphics->anim->z_exit = graphics->exit->instances[0].z;
	return (1);
}

int	ft_allocate_aimg(t_graphics *graphics)
{
	graphics->player_r = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_r)
		return (MALLOC);
	graphics->player_l = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_l)
		return (MALLOC);
	graphics->player_mr = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_mr)
		return (MALLOC);
	graphics->player_ml = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_ml)
		return (MALLOC);
	graphics->player_dead = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_dead)
		return (MALLOC);
	graphics->enemy_cntdwn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_cntdwn)
		return (MALLOC);
	graphics->enemy_explsn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_explsn)
		return (MALLOC);
	graphics->numbers = malloc(sizeof(mlx_image_t *) * 10);
	if (!graphics->numbers)
		return (MALLOC);
	return (SUCCESS);
}

int	ft_set_map_img(t_graphics *graphics, t_map *map)
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
	graphics->wall = ft_draw_asset(graphics->mlx, water, map->walls);
	graphics->space = ft_draw_asset(graphics->mlx, grass, map->spaces);
	graphics->collectable = ft_draw_asset(graphics->mlx, collectable,
			map->collectibles);
	graphics->exit = ft_draw_exit(graphics->mlx, tower, map->exit);
	graphics->enemy = ft_draw_asset(graphics->mlx, enemy, graphics->map->enemy);
	return (1);
}

int	ft_switch_exit_z(void *param)
{
	t_graphics		*graphics;
	mlx_instance_t	*player;
	mlx_image_t		*exit;

	graphics = param;
	player = graphics->player_r[0]->instances;
	exit = graphics->exit;
	if (player->x > exit->instances[0].x - IMG_SIZE
		&& player->x < exit->instances[0].x + IMG_SIZE && player->y
		- HALF_SIZE > exit->instances[0].y - IMG_SIZE && player->y
		+ OSET < exit->instances[0].y + IMG_SIZE + HALF_SIZE)
	{
		mlx_set_instance_depth(graphics->exit->instances,
			graphics->player_dead[ANIM_COUNT - 1]->instances[0].z + 1);
		return (SUCCESS);
	}
	if (graphics->exit->instances->z == graphics->player_dead[ANIM_COUNT
			- 1]->instances[0].z + 1)
		mlx_set_instance_depth(graphics->exit->instances,
			graphics->anim->z_exit);
	return (SUCCESS);
}
