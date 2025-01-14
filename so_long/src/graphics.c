/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/14 13:34:11 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int ft_init_graphics(t_graphics *graphics, char *path)
{
	graphics->map = ft_map_parser(path);
	if (!graphics->map)
		printf("The map could not be used\n");
	else
		printf("The map is good as it is, YAY!\n");
	// Start mlx
	graphics->mlx = mlx_init(graphics->map->width * IMG_SIZE, graphics->map->height * IMG_SIZE, "Whole New World", false);
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
		return (0);
	graphics->player_l = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_l)
		return (0);
	graphics->player_mr = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_mr)
		return (0);
	graphics->player_ml = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_ml)
		return (0);
	graphics->player_dead = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_dead)
		return (0);
	graphics->enemy_cntdwn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_cntdwn)
		return (0);
	graphics->enemy_explsn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_explsn)
		return (0);
	graphics->numbers = malloc(sizeof(mlx_image_t *) * 10);
	if (!graphics->numbers)
		return (0);
	return (1);
}	

int	ft_set_map_img(t_graphics *graphics, t_map *map)
{
	char *water = "./graphics/Terrain/Water.png";
	char *grass = "./graphics/Terrain/Grass_full.png";
	char *collectable = "./graphics/Resources/Shroom.png";
	char *tower = "./graphics/Resources/Tower_Blue_64.png";
	
	graphics->wall = ft_draw_asset(graphics->mlx, water, map->walls);
	graphics->space = ft_draw_asset(graphics->mlx, grass, map->spaces);
	graphics->collectable = ft_draw_asset(graphics->mlx, collectable, map->collectibles);
	graphics->exit = ft_draw_exit(graphics->mlx, tower, map->exit);
	ft_spawn_enemies(graphics, "./graphics/Enemy/Enemy.png");
	return (1);
}

int	ft_switch_exit_z(void *param)
{
	t_graphics	*graphics = param;
	mlx_instance_t *player = graphics->player_r[0]->instances;
	mlx_image_t *exit = graphics->exit;

	if (player->x > exit->instances[0].x - IMG_SIZE && player->x < exit->instances[0].x + IMG_SIZE \
	&& player->y - HALF_SIZE > exit->instances[0].y - IMG_SIZE && player->y + OSET < exit->instances[0].y + IMG_SIZE + HALF_SIZE)
	{
		mlx_set_instance_depth(graphics->exit->instances, graphics->player_dead[ANIM_COUNT - 1]->instances[0].z + 1);
		return (1);
	}
	if (graphics->exit->instances->z == graphics->player_dead[ANIM_COUNT - 1]->instances[0].z + 1)
		mlx_set_instance_depth(graphics->exit->instances, graphics->anim->z_exit);
	return (0);
}






