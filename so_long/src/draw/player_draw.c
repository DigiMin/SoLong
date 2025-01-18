/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:23:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 08:28:16 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

t_game_anim	*ft_set_player_anim(t_graphics *graphics)
{
	t_game_anim	*anim;

	if (ft_alloc_player_imgs(graphics) != SUCCESS)
		return (NULL);
	anim = malloc(sizeof(t_game_anim));
	if (!anim)
		return (NULL);
	anim->numbers = ft_set_counter(graphics);
	ft_set_enemy(graphics, anim);
	ft_disable_all_enemy_anim(graphics, anim);
	anim->player_r = ft_draw_player(graphics, graphics->player_r,
			"./graphics/Warrior/Warrior_r", graphics->map->start);
	anim->player_l = ft_draw_player(graphics, graphics->player_l,
			"./graphics/Warrior/Warrior_l", graphics->map->start);
	anim->player_mr = ft_draw_player(graphics, graphics->player_mr,
			"./graphics/Warrior/Warrior_rmove", graphics->map->start);
	anim->player_ml = ft_draw_player(graphics, graphics->player_ml,
			"./graphics/Warrior/Warrior_lmove", graphics->map->start);
	anim->player_dead = ft_draw_player(graphics, graphics->player_dead,
			"./graphics/Warrior/Warrior_dead", graphics->map->start);
	anim->player_r->enabled = 1;
	return (anim);
}

t_anim	*ft_draw_player(t_graphics *graphics, mlx_image_t **asset, char *path,
		t_coord *coord)
{
	int		i;
	t_anim	*anim;
	char	*c;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	i = 0;
	ft_init_anim_img(anim);
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		asset[i] = ft_draw_asset(graphics->mlx, ft_multi_strjoin(3, path, c,
					".png"), coord);
		if (!asset[i])
			return (NULL);
		free(c);
		i++;
	}
	anim->anim_images = asset;
	ft_switch_display(anim);
	return (anim);
}
