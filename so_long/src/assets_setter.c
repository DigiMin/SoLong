/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/12 12:51:04 by mina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static void	ft_switch_assets(int x, int y, t_map *map);
static void    ft_assets_fill(int x, int y, t_map *map);
// ---------------------- COORD SETTERS ------------------------------- //

// need to reset visited with ft_init_visited
static void    ft_assets_fill(int x, int y, t_map *map)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height || map->visited[y][x] == '1')
        return ;
	ft_switch_assets(x, y, map);
	map->visited[y][x] = '1';
    ft_assets_fill(x + 1, y, map);
    ft_assets_fill(x - 1, y, map);
    ft_assets_fill(x, y + 1, map);
    ft_assets_fill(x, y - 1, map);
}

static void	ft_switch_assets(int x, int y, t_map *map)
{
	if (map->terrain[y][x] == '1' && map->visited[y][x] == '0')
	{
        ft_coord_add_back(&map->walls, ft_coord_new(x, y));
		map->wall_c++;
	}
    else if (map->terrain[y][x] == '0' && map->visited[y][x] == '0')
	{		
		ft_coord_add_back(&map->spaces, ft_coord_new(x, y));
		map->space_c++;
	}
    else if (map->terrain[y][x] == 'C' && map->visited[y][x] == '0')
	{
        ft_coord_add_back(&map->collectibles, ft_coord_new(x, y));
		map->collectible_c++;
	}
	else if (map->terrain[y][x] == 'P' && map->visited[y][x] == '0')
	{
        ft_coord_add_back(&map->start, ft_coord_new(x, y));
		map->start_c++;
	}
	else if (map->terrain[y][x] == 'E' && map->visited[y][x] == '0')
    {
		ft_coord_add_back(&map->exit, ft_coord_new(x, y));
		map->exit_c++;
	}
}

void	ft_set_assets(t_map *map)
{
	ft_allocate_visited(map);
	ft_init_visited(map);
	ft_assets_fill(0, 0, map);
}

