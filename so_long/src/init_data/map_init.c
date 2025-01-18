/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 09:31:08 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int		ft_set_assets(t_map *map);
static t_map	*ft_read_ber(char *path);
static int		ft_set_height(char *path, t_map *map);

// ---------------------- COORD SETTERS ------------------------------- //

// Read the map and init the variables
t_map	*ft_init_map(char *path)
{
	t_map	*map;

	map = ft_read_ber(path);
	if (!map)
		return (NULL);
	ft_init_map_vals(map);
	if (ft_set_assets(map) != SUCCESS)
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
	if (ft_set_height(path, map) != SUCCESS)
		return (NULL);
	map->terrain = malloc(sizeof(char *) * map->height);
	map->terrain[i] = get_next_line(fd);
	while (map->terrain[i])
	{
		i++;
		map->terrain[i] = get_next_line(fd);
	}
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
		return (OPEN);
	row = get_next_line(fd);
	while (row)
	{
		i++;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	close(fd);
	map->height = i;
	return (SUCCESS);
}

static int	ft_set_assets(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_appnd_coord(x, y, map) != SUCCESS)
				return (MALLOC);
			if (ft_appnd_spaces(x, y, map) != SUCCESS)
				return (MALLOC);
			ft_count_assets(x, y, map);
			x++;
		}
		y++;
	}
	if (ft_spawn_enemies(map))
		return (FAILURE);
	return (SUCCESS);
}
