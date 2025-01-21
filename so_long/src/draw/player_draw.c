/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:23:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 10:49:59 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_set_player_anim(t_graphics **graphics, t_game_anim **anim)
{
	(*anim)->player_r = ft_draw_player(graphics,
			(*graphics)->player_r, "./graphics/Warrior/Warrior_r",
			(*graphics)->map->start);
	(*anim)->player_l = ft_draw_player(graphics,
			(*graphics)->player_l, "./graphics/Warrior/Warrior_l",
			(*graphics)->map->start);
	(*anim)->player_mr = ft_draw_player(graphics,
			(*graphics)->player_mr, "./graphics/Warrior/Warrior_rmove",
			(*graphics)->map->start);
	(*anim)->player_ml = ft_draw_player(graphics,
			(*graphics)->player_ml, "./graphics/Warrior/Warrior_lmove",
			(*graphics)->map->start);
	(*anim)->player_dead = ft_draw_player(graphics,
			(*graphics)->player_dead, "./graphics/Warrior/Warrior_dead",
			(*graphics)->map->start);
	(*anim)->player_r->enabled = 1;
}

t_anim	*ft_draw_player(t_graphics **graphics, mlx_image_t **asset, char *path,
		t_coord *coord)
{
	int		i;
	t_anim	*anim;
	char	*c;
	char	*full_path;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (ft_mlx_error(graphics, MALLOC), NULL);
	i = 0;
	ft_init_anim_vals(&anim);
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		full_path = ft_multi_strjoin(3, path, c, ".png");
		if (!full_path)
			return (free(c), ft_mlx_error(graphics, MALLOC), NULL);
		asset[i] = ft_draw_asset(graphics, (*graphics)->mlx, full_path, coord);
		if (!asset[i])
			return (ft_freen(2, c, full_path), ft_mlx_error(graphics,
					MLX_DRAW_FAILURE), NULL);
		ft_freen(2, c, full_path);
		i++;
	}
	anim->anim_images = asset;
	return (anim);
}
