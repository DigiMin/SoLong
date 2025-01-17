/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:20:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:27:18 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_set_enemy(t_graphics *graphics, t_game_anim *anim)
{
	int	i;

	if (ft_alloc_enemy_anim_arr(anim, graphics->map->enemy_c) != SUCCESS)
		return (MALLOC);
	if (ft_set_all_enemy_img(graphics) != SUCCESS)
		return (MALLOC);
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (ft_init_all_enemy_anim(graphics, anim, i) != SUCCESS)
			return (MALLOC);
		i++;
	}
	return (SUCCESS);
}

int	ft_set_all_enemy_img(t_graphics *graphics)
{
	graphics->enemy_cntdwn = ft_set_enemy_img(graphics,
			"./graphics/Enemy/Enemy", graphics->enemy_cntdwn);
	if (!graphics->enemy_cntdwn)
		return (MALLOC);
	graphics->enemy_explsn = ft_set_enemy_img(graphics,
			"./graphics/Effects/Explosion", graphics->enemy_explsn);
	if (!graphics->enemy_explsn)
		return (MALLOC);
	return (SUCCESS);
}

mlx_image_t	**ft_set_enemy_img(t_graphics *graphics, char *path,
		mlx_image_t **asset)
{
	int			i;
	char		*c;
	mlx_image_t	**enemy;

	if (!graphics->map->enemy_c)
		return (NULL);
	i = 0;
	enemy = asset;
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		enemy[i] = ft_draw_asset(graphics->mlx, ft_multi_strjoin(3, path, c,
					".png"), graphics->map->enemy);
		if (!enemy[i])
			return (NULL);
		free(c);
		i++;
	}
	return (enemy);
}

