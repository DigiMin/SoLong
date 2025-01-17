/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:28:40 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:27:01 by honnguye         ###   ########.fr       */
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

int	ft_is_enemy_near(t_graphics *graphics)
{
	mlx_instance_t	*player;
	mlx_instance_t	*enemy;
	int				i;

	player = graphics->player_r[0]->instances;
	enemy = graphics->enemy->instances;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (player->x - OSET > enemy[i].x - (IMG_SIZE * 1.3)
			&& player->x + OSET < enemy[i].x + (IMG_SIZE * 1.3)
			&& player->y - HALF_SIZE > enemy[i].y - (IMG_SIZE * 1.3)
			&& player->y + OSET < enemy[i].y + (IMG_SIZE * 1.3)
			&& graphics->anim->enemy_loops[i] == 4)
			return (NOT_NEAR);
		i++;
	}
	return (SUCCESS);
}



void	ft_animate_enemy(t_graphics *graphics, t_anim_spec spec, int i)
{
	t_game_anim	*anim;
	t_anim		*sprite;

	anim = graphics->anim;
	sprite = ft_spec_anim(anim, spec, i);
	ft_enable_enemy_anim(graphics, spec, i);
	if (sprite->sleep == sprite->anim_speed)
	{
		if (sprite->anim_frame == sprite->anim_count - 1)
		{
			sprite->anim_frame = 0;
			anim->enemy_loops[i]++;
		}
		sprite->anim_frame++;
		sprite->sleep = 0;
	}
	sprite->sleep++;
	ft_switch_enemy_display(graphics, sprite, i);
}

int	ft_enable_enemy_anim(t_graphics *graphics, t_anim_spec spec, int i)
{
	t_game_anim	*anim;

	anim = graphics->anim;
	if (spec == ENEMY_CNTDWN)
	{
		ft_switch_enemy_display(graphics, anim->enemy_cntdwn[i], i);
	}
	else if (spec == ENEMY_EXPLSN)
	{
		ft_switch_enemy_display(graphics, anim->enemy_explsn[i], i);
	}
	return (SUCCESS);
}

void	ft_disable_all_enemy_anim(t_graphics *graphics, t_game_anim *anim)
{
	int	i;

	i = 0;
	while (i < graphics->map->enemy_c)
	{
		ft_disable_enemy_instance(anim, ENEMY_CNTDWN, i);
		ft_disable_enemy_instance(anim, ENEMY_EXPLSN, i);
		i++;
	}
}

void	ft_disable_enemy_instance(t_game_anim *anim, t_anim_spec spec, int i)
{
	int	j;

	j = 0;
	while (j < ANIM_COUNT)
	{
		if (spec == ENEMY_CNTDWN)
			anim->enemy_cntdwn[i]->anim_images[j]->instances[i].enabled = false;
		else if (spec == ENEMY_EXPLSN)
			anim->enemy_explsn[i]->anim_images[j]->instances[i].enabled = false;
		j++;
	}
}

void	ft_switch_enemy_display(t_graphics *graphics, t_anim *asset, int ins)
{
	int	i;
	int	j;

	i = 0;
	while (i < ANIM_COUNT)
	{
		j = 0;
		while (j < graphics->map->enemy_c)
		{
			if (i == asset->anim_frame && j == ins)
				asset->anim_images[i]->instances[j].enabled = true;
			else if (i != asset->anim_frame && j == ins)
				asset->anim_images[i]->instances[j].enabled = false;
			j++;
		}
		i++;
	}
}
