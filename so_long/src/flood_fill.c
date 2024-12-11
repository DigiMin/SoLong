/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:14:41 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/10 12:59:22 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static char **visited;

// This function handles the visited matrix, calls the flood-fill function
// Starting position is player
// Based on if exit and collectable items coordinates are filled, decides if the map is playable
int ft_is_playable()
{
	printf("IN is playable");
	ft_player_init();
	printf("player inited");
	ft_allocate_visited();
	printf("visited allocated");
	ft_init_visited();
	printf("visited initialized");
	ft_flood_fill(player->x, player->y);
	printf("flood fill completed");
	if (collected != game_map->collectible_c || visited[player->next->x][player->next->y] != '1')
		return (0);
	printf("collectible collected");
	return (1);
}

// allocates the memory for the matrix
int ft_allocate_visited()
{
	int i;

	visited = malloc(sizeof(char *) * game_map->height);
	if (!visited)
		return 0;
	i = 0;
	while (i < game_map->height)
	{
		visited[i] = malloc(sizeof(char) * game_map->width);
		if (!visited[i])
			return 0;
		i++;
	}
	return (1);
}

// initialize the visited array with '0' char
void ft_init_visited()
{
	int	i;
	int k;
	
	i = 0;
	while (i < game_map->height)
	{
		k = 0;
		while (k < game_map->width)
		{
			visited[i][k] = '0';
			k++;
		}
		i++;
	}
}

// Path finder, fill the matrix based on the wall boundaries, count the collectable on the way
// Sets the variable to '1' in the visited matrix
void ft_flood_fill(int x, int y)
{
	// define the boundaries
	// if (x <= 0 || y <= 0 || x >= (game_map->width - 1) || y >= (game_map->height - 1))
	// 	return ;
	// define walls
	if (game_map->map_terrain[y][x] == '1' || visited[y][x] == '1')
		return ;
	// count the collectible if not encountered
	if (game_map->map_terrain[y][x] == 'C' && visited[y][x] == '0')
		collected++;
	// change visited[x][y] to  '1'
	visited[y][x] = '1';
	// try different paths
	ft_flood_fill(x + 1, y);
	ft_flood_fill(x - 1, y);
	ft_flood_fill(x, y + 1);
	ft_flood_fill(x, y - 1);
}

// free the visited matrix if something fails
void ft_free_matrix(char **arr, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}