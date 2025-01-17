/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:36:37 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:37:18 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"


int	ft_get_max_enemy_count(t_map *map)
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

int	ft_get_random_spawn_index(t_map *map)
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

int	ft_is_enemy_spawnable(t_map *map, t_coord *coord)
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

int	ft_not_around_player(t_map *map, t_coord *coord)
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