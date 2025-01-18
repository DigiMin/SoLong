/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 08:44:41 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_enable_anim(t_game_anim *anim, t_anim_spec spec)
{
	t_anim	*player;

	player = ft_spec_anim(anim, spec, 0);
	anim->player_r->enabled = 0;
	anim->player_l->enabled = 0;
	anim->player_mr->enabled = 0;
	anim->player_ml->enabled = 0;
	anim->player_dead->enabled = 0;
	player->enabled = 1;
	ft_switch_display(anim->player_r);
	ft_switch_display(anim->player_l);
	ft_switch_display(anim->player_mr);
	ft_switch_display(anim->player_ml);
	ft_switch_display(anim->player_dead);
	return (SUCCESS);
}
