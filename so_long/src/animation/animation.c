/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:58:16 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 19:27:09 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_animate(void *param, t_anim_spec spec)
{
	t_game_anim	*anim;
	t_anim		*sprite;

	anim = param;
	sprite = ft_spec_anim(anim, spec, 0);
	ft_enable_anim(anim, spec);
	sprite->enabled = 1;
	if (sprite->sleep == sprite->anim_speed)
	{
		if (sprite->anim_frame == sprite->anim_count - 1)
			sprite->anim_frame = 0;
		sprite->anim_frame++;
		sprite->sleep = 0;
	}
	sprite->sleep++;
	ft_switch_display(sprite);
}

t_anim	*ft_spec_anim(t_game_anim *anim, t_anim_spec spec, int instance)
{
	if (spec == PLAYER_R)
		return (anim->player_r);
	else if (spec == PLAYER_L)
		return (anim->player_l);
	else if (spec == PLAYER_MR)
		return (anim->player_mr);
	else if (spec == PLAYER_ML)
		return (anim->player_ml);
	else if (spec == PLAYER_DEAD)
		return (anim->player_dead);
	else if (spec == ENEMY_CNTDWN)
		return (anim->enemy_cntdwn[instance]);
	else if (spec == ENEMY_EXPLSN)
		return (anim->enemy_explsn[instance]);
	return (NULL);
}

/*
 * @brief Switches the display of each animation
 * based on which anim_frame is active
 *		- if the animation is not enabled, all images are disabled
 *
 * @param asset The animation structure
 *
 * @return void
 */
void	ft_switch_display(t_anim *asset)
{
	int	i;

	i = 0;
	if (!asset)
		return ;
	if (!asset->enabled)
	{
		while (i < asset->anim_count)
		{
			asset->anim_images[i]->enabled = false;
			i++;
		}
		return ;
	}
	i = 0;
	while (i < asset->anim_count)
	{
		if (i == asset->anim_frame)
			asset->anim_images[i]->enabled = true;
		else
			asset->anim_images[i]->enabled = false;
		i++;
	}
}
