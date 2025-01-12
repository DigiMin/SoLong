/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:38:10 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/12 22:57:51 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

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
int ft_not_around_player(t_map *map, t_coord *coord)
{
	if (map->terrain[coord->y][coord->x] == 'P')
		return (0);
	if (map->terrain[coord->y + 1][coord->x] == 'P')
		return (0);
	if (map->terrain[coord->y - 1][coord->x] == 'P')
		return (0);
	if (map->terrain[coord->y][coord->x + 1] == 'P')
		return (0);
	if (map->terrain[coord->y][coord->x - 1] == 'P')
		return (0);
	if (map->terrain[coord->y + 1][coord->x + 1] == 'P')
		return (0);
	if (map->terrain[coord->y - 1][coord->x - 1] == 'P')
		return (0);
	if (map->terrain[coord->y - 1][coord->x + 1] == 'P')
		return (0);
	if (map->terrain[coord->y + 1][coord->x - 1] == 'P')
		return (0);
	return (1);
}

int	ft_is_enemy_spawnable(t_map *map, t_coord *coord)
{
	if (map->terrain[coord->y][coord->x] != '0')
		return (0);
	if (map->terrain[coord->y + 1][coord->x] == 'E')
		return (0);
	if (map->terrain[coord->y][coord->x] == 'E')
		return (0);
	if (map->terrain[coord->y][coord->x] == 'C')
		return (0);
	if (!ft_not_around_player(map, coord))
		return (0);
	return (1);
}

int	ft_get_max_enemy_count(t_map *map)
{
	int		count;
	int		d;

	if (map->space_c < 10)
		return (0);
	if (map->space_c < 20)
		d = 2;
	else if (map->space_c < 30)
		d = 3;
	else if (map->space_c < 40)
		d = 4;
	else
		d = 5;
	printf("SPACE COUNT: %d\n", map->space_c);
	printf("DIVISOR: %d\n", d);
	// TODO: if the map is small reduce the enemy count
	count = ft_get_random_spawn_index(map) % d;
	printf("ENEMY COUNT: %d\n", count);
	if (count == 0)
		count++;
	return (count);
}

void	ft_spawn_enemies(t_graphics *graphics, char *path)
{
	int		random_pos;
	t_coord	*coord;
	int		i;

	i = 0;
	graphics->map->enemy_c = ft_get_max_enemy_count(graphics->map);
	if (graphics->map->enemy_c == 0)
		return ;
	while (i < graphics->map->enemy_c)
	{
		random_pos = ft_get_random_spawn_index(graphics->map);
		coord = ft_get_nth_coord(graphics->map->spaces, random_pos);
		while (!ft_is_enemy_spawnable(graphics->map, coord))
		{
			random_pos = ft_get_random_spawn_index(graphics->map);
			coord = ft_get_nth_coord(graphics->map->spaces, random_pos);
		}
		ft_coord_add_back(&graphics->map->enemy, ft_coord_new(coord->x, coord->y));
		i++;
	}
	graphics->enemy = ft_draw_asset(graphics->mlx, path, graphics->map->enemy);
}
