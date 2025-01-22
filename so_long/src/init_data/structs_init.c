/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:06 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/22 15:28:46 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_init_anim_vals(t_anim **anim)
{
	(*anim)->anim_count = ANIM_COUNT;
	(*anim)->anim_frame = 0;
	(*anim)->sleep = 0;
	(*anim)->anim_speed = ANIM_SPEED;
	(*anim)->enabled = 0;
}

void	ft_init_map_vals(t_map **map)
{
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->terrain = NULL;
	(*map)->visited = NULL;
	(*map)->start_c = 0;
	(*map)->exit_c = 0;
	(*map)->space_c = 0;
	(*map)->collectible_c = 0;
	(*map)->wall_c = 0;
	(*map)->move_c = 0;
	(*map)->start = NULL;
	(*map)->exit = NULL;
	(*map)->spaces = NULL;
	(*map)->collectibles = NULL;
	(*map)->walls = NULL;
	(*map)->enemy = NULL;
}

void	ft_init_graphics_vals(t_graphics **graphics)
{
	(*graphics)->anim = ft_set_game_anim(graphics);
	(*graphics)->map->collected = 0;
	(*graphics)->can_move = 1;
	(*graphics)->last_anim_dir = PLAYER_MR;
	(*graphics)->cngrts = ft_draw_bckgrnd(graphics, "./graphics/UI/cb1.png");
	(*graphics)->failed = ft_draw_bckgrnd(graphics, "./graphics/UI/cb2.png");
	(*graphics)->cngrts->enabled = 0;
	(*graphics)->failed->enabled = 0;
	(*graphics)->anim->z_exit = (*graphics)->exit->instances[0].z;
}
