/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:06 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 10:34:33 by honnguye         ###   ########.fr       */
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
