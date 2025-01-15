/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:38:10 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/15 23:43:21 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_get_max_enemy_count(t_map *map);
static int	ft_get_random_spawn_index(t_map *map);
static int	ft_is_enemy_spawnable(t_map *map, t_coord *coord);
static int	ft_not_around_player(t_map *map, t_coord *coord);

int	ft_spawn_enemies(t_map *map)
{
	int		i;

	i = 0;
	map->enemy_c = ft_get_max_enemy_count(map);
	if (map->enemy_c == 0)
		return (SUCCESS);
	while (i < map->enemy_c)
	{
		if (ft_add_enemy(map) != SUCCESS)
			return (MALLOC);
		i++;
	}
	return (SUCCESS);
}

int ft_add_enemy(t_map *map)
{
	int		random_pos;
	t_coord	*coord;
	t_coord	*enemy;

	random_pos = ft_get_random_spawn_index(map);
	coord = ft_get_nth_coord(map->spaces, random_pos);
	while (ft_is_enemy_spawnable(map, coord) != SUCCESS)
	{
		random_pos = ft_get_random_spawn_index(map);
		coord = ft_get_nth_coord(map->spaces, random_pos);
	}
	enemy = ft_coord_new(coord->x, coord->y);
	if (!enemy)
		return (MALLOC);
	ft_coord_add_back(&map->enemy, enemy);
	return (SUCCESS);
}

static int	ft_get_max_enemy_count(t_map *map)
{
	int	count;
	int	d;

	if (map->space_c < 10)
		return (SUCCESS);
	if (map->space_c < 20)
		d = 2;
	else if (map->space_c < 30)
		d = 3;
	else if (map->space_c < 40)
		d = 4;
	else
		d = 5;
	count = ft_get_random_spawn_index(map) % d;
	if (count == 0)
		count++;
	return (count);
}

static int	ft_get_random_spawn_index(t_map *map)
{
	int		fd;
	char	*rnd_line;
	int		random;

	fd = open("/dev/random", O_RDONLY);
	rnd_line = get_next_line(fd);
	random = ft_gnl_strlen(rnd_line, '\0') % map->space_c;
	free(rnd_line);
	close(fd);
	return (random);
}

static int	ft_is_enemy_spawnable(t_map *map, t_coord *coord)
{
	if (map->terrain[coord->y][coord->x] != '0')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y + 1][coord->x] == 'E')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y][coord->x] == 'E')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y][coord->x] == 'C')
		return (ENEMY_NOT_SPAWNABLE);
	if (ft_not_around_player(map, coord) != SUCCESS)
		return (ENEMY_NOT_SPAWNABLE);
	return (SUCCESS);
}

static int	ft_not_around_player(t_map *map, t_coord *coord)
{
	if (map->terrain[coord->y][coord->x] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y + 1][coord->x] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y - 1][coord->x] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y][coord->x + 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y][coord->x - 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y + 1][coord->x + 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y - 1][coord->x - 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y - 1][coord->x + 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	if (map->terrain[coord->y + 1][coord->x - 1] == 'P')
		return (ENEMY_NOT_SPAWNABLE);
	return (SUCCESS);
}
