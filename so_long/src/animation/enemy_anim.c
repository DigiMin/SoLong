/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:39 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 09:30:31 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

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
