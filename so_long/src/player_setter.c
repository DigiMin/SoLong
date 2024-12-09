/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 22:08:49 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// ---------------------- PLAYER HELPERS ------------------------------- //

void ft_player_init()
{
	player = ft_coord_new(0, 0);
	ft_find_set_coords(player, 'P');
}

void ft_update_player_pos(int x, int y)
{
	player->x = x;
	player->y = y;
}
