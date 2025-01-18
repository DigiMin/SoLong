/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:02:48 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 08:44:05 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_alloc_player_imgs(t_graphics *graphics)
{
	graphics->player_r = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_r)
		return (MALLOC);
	graphics->player_l = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_l)
		return (MALLOC);
	graphics->player_mr = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_mr)
		return (MALLOC);
	graphics->player_ml = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_ml)
		return (MALLOC);
	graphics->player_dead = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->player_dead)
		return (MALLOC);
	graphics->enemy_cntdwn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_cntdwn)
		return (MALLOC);
	graphics->enemy_explsn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!graphics->enemy_explsn)
		return (MALLOC);
	graphics->numbers = malloc(sizeof(mlx_image_t *) * 10);
	if (!graphics->numbers)
		return (MALLOC);
	return (SUCCESS);
}

int	ft_alloc_enemy_anim_arr(t_game_anim *anim, int count)
{
	anim->enemy_cntdwn = malloc(sizeof(t_anim *) * count);
	if (!anim->enemy_cntdwn)
		return (MALLOC);
	anim->enemy_explsn = malloc(sizeof(t_anim *) * count);
	if (!anim->enemy_explsn)
		return (MALLOC);
	anim->enemy_loops = malloc(sizeof(int) * count);
	if (!anim->enemy_loops)
		return (MALLOC);
	return (SUCCESS);
}
