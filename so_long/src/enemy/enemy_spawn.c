/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:38:10 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 20:26:28 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_spawn_enemies(t_graphics **graphics, t_map *map)
{
	int	i;

	i = 0;
	map->enemy_c = ft_get_max_enemy_count(map);
	if (map->enemy_c == 0)
		return (SUCCESS);
	while (i < map->enemy_c)
	{
		if (ft_add_enemy(graphics, map) != SUCCESS)
			return (MALLOC);
		i++;
	}
	return (SUCCESS);
}

int	ft_add_enemy(t_graphics **graphics, t_map *map)
{
	int		random_pos;
	t_coord	*coord;

	random_pos = ft_get_random_spawn_index(map);
	coord = ft_get_nth_coord(map->spaces, random_pos);
	while (ft_is_enemy_spawnable(map, coord) != SUCCESS)
	{
		random_pos = ft_get_random_spawn_index(map);
		coord = ft_get_nth_coord(map->spaces, random_pos);
	}
	ft_coord_add_back(graphics, &map->enemy, coord->x, coord->y);
	return (SUCCESS);
}
