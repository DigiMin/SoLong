/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:14:41 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 12:17:19 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static void	ft_flood_fill(int x, int y, t_map *map);
static int	ft_allocate_visited(t_map *map);
static void	ft_init_visited(t_map *map);

// This function handles the visited matrix, calls the flood-fill function
// The map validator calls this function to try paths
// Based on if exit and collectable items coordinates are filled,
//	decides if the map is playable
int	ft_is_playable(t_map *map)
{
	int	ret;

	ret = SUCCESS;
	if (!map)
		return (FAILURE);
	if (ft_allocate_visited(map) != SUCCESS)
		return (MALLOC);
	ft_init_visited(map);
	map->collected = 0;
	ft_flood_fill(map->start->x, map->start->y, map);
	if (map->visited[map->exit->y][map->exit->x] != '1')
		return (NOT_PLAYABLE);
	if (map->collected != map->collectible_c)
		return (NOT_PLAYABLE);
	return (SUCCESS);
}

// allocates the memory for the matrix
static int	ft_allocate_visited(t_map *map)
{
	int	i;

	map->visited = malloc(sizeof(char *) * map->height);
	if (!map->visited)
		return (MALLOC);
	i = 0;
	while (i < map->height)
	{
		map->visited[i] = malloc(sizeof(char) * map->width);
		if (!map->visited[i])
			return (MALLOC);
		i++;
	}
	return (SUCCESS);
}

// initialize the visited array with '0' char
static void	ft_init_visited(t_map *map)
{
	int	i;
	int	k;

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

// Path finder, fill the matrix based on the wall boundaries,
//	count the collectable on the way
// Sets the variable to '1' in the visited matrix
static void	ft_flood_fill(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
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
