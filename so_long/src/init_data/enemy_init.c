/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:15:18 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 10:56:15 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_init_all_enemy_anim(t_graphics **graphics, t_game_anim *anim, int i)
{
	anim->enemy_cntdwn[i] = ft_init_enemy_anim((*graphics)->enemy_cntdwn);
	if (!anim->enemy_cntdwn[i])
		return (MALLOC);
	anim->enemy_explsn[i] = ft_init_enemy_anim((*graphics)->enemy_explsn);
	if (!anim->enemy_explsn[i])
		return (MALLOC);
	anim->enemy_loops[i] = 0;
	return (SUCCESS);
}

t_anim	*ft_init_enemy_anim(mlx_image_t **asset)
{
	int		i;
	t_anim	*anim;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	i = 0;
	ft_init_anim_img(anim);
	anim->enabled = 1;
	anim->anim_images = asset;
	return (anim);
}
