/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 20:47:21 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_free_map(int height, t_map **map)
{
	if (!map)
		return ;
	if ((*map)->terrain)
		ft_free_matrix((*map)->terrain, height);
	if ((*map)->visited)
		ft_free_matrix((*map)->visited, height);
	if ((*map)->start)
		ft_free_coords(&(*map)->start);
	if ((*map)->exit)
		ft_free_coords(&(*map)->exit);
	if ((*map)->spaces)
		ft_free_coords(&(*map)->spaces);
	if ((*map)->collectibles)
		ft_free_coords(&(*map)->collectibles);
	if ((*map)->walls)
		ft_free_coords(&(*map)->walls);
	if ((*map)->enemy)
		ft_free_coords(&(*map)->enemy);
	free((*map));
	(*map) = NULL;
}

void	ft_free_player_anim(t_game_anim **anim)
{
	if ((*anim)->player_l)
	{
		free((*anim)->player_l);
		(*anim)->player_l = NULL;
	}
	if ((*anim)->player_r)
	{
		free((*anim)->player_r);
		(*anim)->player_r = NULL;
	}
	if ((*anim)->player_ml)
	{
		free((*anim)->player_ml);
		(*anim)->player_ml = NULL;
	}
	if ((*anim)->player_mr)
	{
		free((*anim)->player_mr);
		(*anim)->player_mr = NULL;
	}
	if ((*anim)->player_dead)
	{
		free((*anim)->player_dead);
		(*anim)->player_dead = NULL;
	}
}

void	ft_free_game_anim(t_graphics **graphics, t_game_anim **anim)
{
	if (!*anim)
		return ;
	ft_free_player_anim(anim);
	if ((*anim)->enemy_cntdwn)
		ft_free_anim_array((*anim)->enemy_cntdwn, (*graphics)->map->enemy_c);
	if ((*anim)->enemy_explsn)
		ft_free_anim_array((*anim)->enemy_explsn, (*graphics)->map->enemy_c);
	if ((*anim)->numbers)
		ft_free_anim_array((*anim)->numbers, ANIM_COUNT);
	if ((*anim)->enemy_loops)
	{
		free((*anim)->enemy_loops);
		(*anim)->enemy_loops = NULL;
	}
	free((*anim));
	(*anim) = NULL;
}

void	ft_free_graphics(t_graphics **graphics)
{
	if (!graphics)
		return ;
	if ((*graphics)->anim)
	{
		ft_free_game_anim(graphics, &(*graphics)->anim);
		(*graphics)->anim = NULL;
	}
	if ((*graphics)->map)
	{
		ft_free_map((*graphics)->map->height, &(*graphics)->map);
		(*graphics)->map = NULL;
	}
	if ((*graphics)->mlx)
	{
		mlx_terminate((*graphics)->mlx);
		(*graphics)->mlx = NULL;
	}
}
