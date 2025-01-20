/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:28:40 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/19 22:50:53 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_enemy_touched(void *param)
{
	t_graphics		*graphics;
	mlx_instance_t	*player;
	mlx_instance_t	*enemy;
	int				i;

	graphics = param;
	player = graphics->player_r[0]->instances;
	enemy = graphics->enemy->instances;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (player->x - OSET > enemy[i].x - IMG_SIZE && player->x
			+ OSET < enemy[i].x + IMG_SIZE && player->y - HALF_SIZE > enemy[i].y
			- IMG_SIZE && player->y + OSET < enemy[i].y + IMG_SIZE)
		{
			if (graphics->anim->enemy_loops[i] == 0)
				graphics->anim->enemy_loops[i] = 1;
			return (i);
		}
		i++;
	}
	return (INSTANCE_NOT_TOUCHED);
}

int	ft_is_exploding(t_graphics *graphics)
{
	mlx_instance_t	*player;
	mlx_instance_t	*enemy;
	int				i;

	player = graphics->player_r[0]->instances;
	enemy = graphics->enemy->instances;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (player->x - OSET > enemy[i].x - (IMG_SIZE * 1.3) && player->x
			+ OSET < enemy[i].x + (IMG_SIZE * 1.3) && player->y
			- HALF_SIZE > enemy[i].y - (IMG_SIZE * 1.3) && player->y
			+ OSET < enemy[i].y + (IMG_SIZE * 1.3)
			&& graphics->anim->enemy_loops[i] == EXPLOSION_LOOP)
			return (NOT_NEAR);
		i++;
	}
	return (SUCCESS);
}

void	ft_enemy_handler(t_graphics *graphics)
{
	int	instance;
	int	i;

	if (graphics->map->enemy_c)
	{
		instance = ft_enemy_touched(graphics);
		if (instance >= 0)
			graphics->enemy->instances[instance].enabled = false;
	}
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (ft_is_exploding(graphics) && graphics->anim->enemy_loops[i] == EXPLOSION_LOOP)
			graphics->can_move = 0;
		ft_explode(graphics, i);
		i++;
	}
}

void	ft_explode(t_graphics *graphics, int i)
{
	if (graphics->anim->enemy_loops[i] > 0
		&& graphics->anim->enemy_loops[i] < EXPLOSION_LOOP)
		ft_animate_enemy(graphics, ENEMY_CNTDWN, i);
	if (graphics->anim->enemy_loops[i] == EXPLOSION_LOOP)
	{
		ft_disable_enemy_instance(graphics->anim, ENEMY_CNTDWN, i);
		ft_animate_enemy(graphics, ENEMY_EXPLSN, i);
	}
	if (graphics->anim->enemy_loops[i] == EXPLOSION_LOOP + 1)
	{
		ft_disable_enemy_instance(graphics->anim, ENEMY_EXPLSN, i);
		graphics->anim->enemy_loops[i] = 10;
	}
}
