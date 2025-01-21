/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:20:22 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 10:48:39 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_set_enemy(t_graphics **graphics, t_game_anim **anim)
{
	int	i;

	if (ft_alloc_enemy_anim_arr(graphics, anim,
			(*graphics)->map->enemy_c) != SUCCESS)
		ft_mlx_error(graphics, MALLOC);
	ft_set_all_enemy_img(graphics);
	i = 0;
	while (i < (*graphics)->map->enemy_c)
	{
		ft_init_all_enemy_anim(graphics, anim, i);
		i++;
	}
}

void	ft_set_all_enemy_img(t_graphics **graphics)
{
	(*graphics)->enemy_cntdwn = ft_draw_enemies(graphics,
			"./graphics/Enemy/Enemy", (*graphics)->enemy_cntdwn);
	(*graphics)->enemy_explsn = ft_draw_enemies(graphics,
			"./graphics/Effects/Explosion", (*graphics)->enemy_explsn);
}

mlx_image_t	**ft_draw_enemies(t_graphics **graphics, char *path,
		mlx_image_t **asset)
{
	int			i;
	char		*c;
	char		*full_path;
	mlx_image_t	**enemy;

	if (!(*graphics)->map->enemy_c)
		return (NULL);
	i = 0;
	enemy = asset;
	while (i < ANIM_COUNT)
	{
		c = ft_itoa(i);
		full_path = ft_multi_strjoin(3, path, c, ".png");
		if (!full_path)
			return (free(c), ft_error(graphics, MALLOC), NULL);
		enemy[i] = ft_draw_asset(graphics, (*graphics)->mlx, full_path,
				(*graphics)->map->enemy);
		if (!enemy[i])
			return (ft_freen(2, c, full_path), ft_error(graphics,
					MLX_DRAW_FAILURE), NULL);
		ft_freen(2, c, full_path);
		i++;
	}
	return (enemy);
}
