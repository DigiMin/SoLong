/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:14:41 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 23:27:19 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static char **visited;

void ft_free_matrix(char **arr, int height);

// allocates the memory for the matrix
void ft_allocate_visited()
{
	int i;
	int k;

	visited = malloc(sizeof(char *) * game_map->height);
	if (!visited)
		return ;
	i = 0;
	while (i < game_map->height)
	{
		visited[i] = malloc(sizeof(char) * game_map->width);
		if (!visited[i])
		{
			ft_free_matrix(visited, i);
			return ;
		}
		i++;
	}
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

// path finder
void ft_flood_fill(int x, int y)
{
	// define the boundaries
	if (x == 0 || y == 0 || x == game_map->width - 1 || y == game_map->height - 1)
		return ;
	// define walls
	if (game_map->map_terrain[x][y] == '1' || visited[x][y] == '1')
		return ;
	// change visited[x][y] to  '1'
	visited[x][y] = '1';
	// try different paths
	ft_flood_fill(x + 1, y);
	ft_flood_fill(x - 1, y);
	ft_flood_fill(x, y + 1);
	ft_flood_fill(x, y - 1);
}

// TODO if visited collectables == game_collectable && exit coordinates are inside too the map is valid
void ft_is_playable()
{	
	if (collected == game_map->collectible_c)
	{
		game_map->is_playable = 1;
		return ;
	}	
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