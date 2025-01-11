/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:14:41 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/29 16:22:32 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static void ft_flood_fill(int x, int y, t_map *map);
static int	ft_allocate_visited(t_map *map);
static void	ft_init_visited(t_map *map);

// This function handles the visited matrix, calls the flood-fill function
// The map validator calls this function to try paths
// Based on if exit and collectable items coordinates are filled, decides if the map is playable
int ft_is_playable(t_map *map)
{
	ft_allocate_visited(map);
	ft_init_visited(map);
	ft_flood_fill(map->start->x, map->start->y, map);
	if (map->collected != map->collectible_c || map->visited[map->exit->y][map->exit->x] != '1')
		return (0);
	return (1);
}

// allocates the memory for the matrix
static int	ft_allocate_visited(t_map *map)
{
	int i;

	map->visited = malloc(sizeof(char *) * map->height);
	if (!map->visited)
		return 0;
	i = 0;
	while (i < map->height)
	{
		map->visited[i] = malloc(sizeof(char) * map->width);
		if (!map->visited[i]) 
			return 0;
		i++;
	}
	return (1);
}

// initialize the visited array with '0' char
static void ft_init_visited(t_map *map)
{
	int	i;
	int k;
	
	i = 0;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->visited[i][k] = '0';
			k++;
		}
		i++;
	}
}

// Path finder, fill the matrix based on the wall boundaries, count the collectable on the way
// Sets the variable to '1' in the visited matrix
static void ft_flood_fill(int x, int y, t_map *map)
{
	if (map->terrain[y][x] == '1' || map->visited[y][x] == '1')
		return ;
	if (map->terrain[y][x] == 'C' && map->visited[y][x] == '0')
		map->collected++;
	map->visited[y][x] = '1';
	ft_flood_fill(x + 1, y, map);
	ft_flood_fill(x - 1, y, map);
	ft_flood_fill(x, y + 1, map);
	ft_flood_fill(x, y - 1, map);
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