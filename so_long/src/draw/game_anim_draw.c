/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_anim_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:03 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 13:50:53 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

t_game_anim	*ft_set_game_anim(t_graphics **graphics)
{
	t_game_anim	*anim;

	if (ft_alloc_player_imgs(graphics) != SUCCESS)
		return (ft_mlx_error(graphics, MALLOC), NULL);
	anim = malloc(sizeof(t_game_anim));
	if (!anim)
		return (ft_mlx_error(graphics, MALLOC), NULL);
	anim->numbers = ft_set_counter(graphics);
	ft_set_enemy(graphics, &anim);
	ft_disable_all_enemy_anim(*graphics, anim);
	ft_set_player_anim(graphics, &anim);
	return (anim);
}
