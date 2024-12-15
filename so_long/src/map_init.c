/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/15 11:36:52 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static void	ft_switch_assets(int x, int y, t_map *map);
static void	ft_set_assets(t_map *map);

// ---------------------- COORD SETTERS ------------------------------- //

// Read the map and init the variables
t_map	*ft_init_map(char *path)
{
	int		i;
	int		fd;
	t_map	*map;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->terrain = malloc(sizeof(char *) * 20);
	while ((map->terrain[i] = get_next_line(fd)))
		i++;
	close(fd);
	map->height = i;
	map->width = ft_gnl_strlen(map->terrain[0], '\0') - 1; // -1 for new line
	map->start_c = 0;
	map->exit_c = 0;
	map->space_c = 0;
	map->collectible_c = 0;
	map->wall_c = 0;
	ft_set_assets(map);
	return (map);
}

// need to reset visited with ft_init_visited
static void    ft_set_assets(t_map *map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_switch_assets(x, y, map);
			x++;
		}
		y++;
	}
}

static void	ft_switch_assets(int x, int y, t_map *map)
{
	if (map->terrain[y][x] == '1')
	{
        ft_coord_add_back(&map->walls, ft_coord_new(x, y));
		map->wall_c++;
	}
    else if (map->terrain[y][x] == '0')
	{		
		ft_coord_add_back(&map->spaces, ft_coord_new(x, y));
		map->space_c++;
	}
    else if (map->terrain[y][x] == 'C')
	{
        ft_coord_add_back(&map->collectibles, ft_coord_new(x, y));
        ft_coord_add_back(&map->spaces, ft_coord_new(x, y));
		map->collectible_c++;
	}
	else if (map->terrain[y][x] == 'P')
	{
        ft_coord_add_back(&map->start, ft_coord_new(x, y));
        ft_coord_add_back(&map->spaces, ft_coord_new(x, y));
		map->start_c++;
	}
	else if (map->terrain[y][x] == 'E')
    {
		ft_coord_add_back(&map->exit, ft_coord_new(x, y));
        ft_coord_add_back(&map->spaces, ft_coord_new(x, y));
		map->exit_c++;
	}
}


