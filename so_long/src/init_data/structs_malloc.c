/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:02:48 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:14 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_alloc_player_imgs(t_graphics **graphics)
{
	(*graphics)->player_r = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->player_r)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->player_l = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->player_l)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->player_mr = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->player_mr)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->player_ml = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->player_ml)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->player_dead = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->player_dead)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->numbers = malloc(sizeof(mlx_image_t *) * 10);
	if (!(*graphics)->numbers)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	ft_alloc_enemy_img_arr(graphics);
	return (SUCCESS);
}

int ft_alloc_enemy_img_arr(t_graphics **graphics)
{
	if ((*graphics)->map->enemy_c == 0)
		return (SUCCESS);
	(*graphics)->enemy_cntdwn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->enemy_cntdwn)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*graphics)->enemy_explsn = malloc(sizeof(mlx_image_t *) * ANIM_COUNT);
	if (!(*graphics)->enemy_explsn)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	return (SUCCESS);
}

int	ft_alloc_enemy_anim_arr(t_graphics **graphics, t_game_anim **anim,
		int count)
{
	(*anim)->enemy_cntdwn = malloc(sizeof(t_anim *) * count);
	if (!(*anim)->enemy_cntdwn)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*anim)->enemy_explsn = malloc(sizeof(t_anim *) * count);
	if (!(*anim)->enemy_explsn)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	(*anim)->enemy_loops = malloc(sizeof(int) * count);
	if (!(*anim)->enemy_loops)
		return (ft_mlx_error(graphics, MALLOC), MALLOC);
	return (SUCCESS);
}
