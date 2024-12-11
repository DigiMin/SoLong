/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/10 12:24:13 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// ---------------------- PLAYER HELPERS ------------------------------- //

void ft_player_init()
{
	printf("-----INplayer init-----");

	// malloc new node for player
	player = ft_coord_new(0, 0);
	printf("player allocated");
	// find the coordinates, and set them
	ft_find_set_coords(player, 'P');
	printf("player coords set");
	// add an exit node for the player
	ft_coord_add_back(&player, ft_coord_new(0, 0));
	printf("exit allocated behind player node and added to back");
	// find and set the coordinates for the exit node
	ft_find_set_coords(player->next, 'E');
	printf("exit node set");
}

void ft_update_player_pos(int x, int y)
{
	player->x = x;
	player->y = y;
}

