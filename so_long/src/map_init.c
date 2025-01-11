/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/08 23:38:23 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static void ft_count_assets(int x, int y, t_map *map);
static int	ft_appnd_coord(int x, int y, t_map *map);
static int	ft_appnd_spaces(int x, int y, t_map *map);
static int	ft_set_assets(t_map *map);
static t_map	*ft_read_ber(char *path);
static int	ft_set_height(char *path, t_map *map);

// ---------------------- COORD SETTERS ------------------------------- //

// Read the map and init the variables
t_map	*ft_init_map(char *path)
{
	t_map	*map;

	map = ft_read_ber(path);
	if (!map)
		return (NULL);
	map->width = ft_gnl_strlen(map->terrain[0], '\0') - 1; // -1 for new line
	map->start_c = 0;
	map->exit_c = 0;
	map->space_c = 0;
	map->collectible_c = 0;
	map->wall_c = 0;
	map->move_c = 0;
	// map->collected = 0;
	if (!ft_set_assets(map))
		return (NULL);
	return (map);
}

static t_map	*ft_read_ber(char *path)
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
	if (!ft_set_height(path, map))
		return (NULL);
	map->terrain = malloc(sizeof(char *) * map->height);
	while ((map->terrain[i] = get_next_line(fd)))
		i++;
	close(fd);
	return (map);
}

static int	ft_set_height(char *path, t_map *map)
{
	int		i;
	int		fd;
	char	*row;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((row = get_next_line(fd)))
	{
		i++;
		free(row);
	}
	close(fd);
	map->height = i;
	return (1);
}

static int    ft_set_assets(t_map *map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_appnd_coord(x, y, map))
				return (0);
			if (!ft_appnd_spaces(x, y, map))
				return (0);
			ft_count_assets(x, y, map);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_appnd_coord(int x, int y, t_map *map)
{
	t_coord *new = ft_coord_new(x, y);
	if (!new)
		return (0);
	if (map->terrain[y][x] == '1')
        ft_coord_add_back(&map->walls, new);
    else if (map->terrain[y][x] == '0')	
		ft_coord_add_back(&map->spaces, new);
    else if (map->terrain[y][x] == 'C')
        ft_coord_add_back(&map->collectibles, new);
	else if (map->terrain[y][x] == 'P')
        ft_coord_add_back(&map->start, new);
	else if (map->terrain[y][x] == 'E')
		ft_coord_add_back(&map->exit, new);
	return (1);
}

static int	ft_appnd_spaces(int x, int y, t_map *map)
{
	t_coord *new = ft_coord_new(x, y);
	if (!new)
		return (0);
	if (map->terrain[y][x] == 'C')
        ft_coord_add_back(&map->spaces, new);
	else if (map->terrain[y][x] == 'P')
        ft_coord_add_back(&map->spaces, new);
	else if (map->terrain[y][x] == 'E')
        ft_coord_add_back(&map->spaces, new);
	return (1);
}

static void ft_count_assets(int x, int y, t_map *map)
{
	if (map->terrain[y][x] == '1')
		map->wall_c++;
    else if (map->terrain[y][x] == '0')
		map->space_c++;
    else if (map->terrain[y][x] == 'C')
		map->collectible_c++;
	else if (map->terrain[y][x] == 'P')
		map->start_c++;
	else if (map->terrain[y][x] == 'E')
		map->exit_c++;
}

