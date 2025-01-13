/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:29 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/13 13:30:25 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_rectangular_check(t_map *map);
static int	ft_min_char_validator(t_map *map);
static int	ft_map_frame_check(t_map *map);
static int	ft_check_extension(char *path);

// -------------------------------- MAP VALIDATORS -------------------------------

// map min height and width needs to be 4
// width must be the same on each line
t_map	*ft_map_parser(char *path)
{
	t_map	*map;

	if (!ft_check_extension(path))
		return (NULL);
	map = ft_init_map(path);
	if (!map)
		return (NULL);
	if (!ft_rectangular_check(map))
		return (NULL);
	if (!ft_map_frame_check(map))
		return (NULL);
	if (!ft_min_char_validator(map))
		return (NULL);
	if (!ft_is_playable(map))
		return (NULL);
	return (map);
}

// -------------------------------- MAP HELPERS -------------------------------

static int	ft_check_extension(char *path)
{
	size_t	i;

	i = ft_gnl_strlen(path, '\0');
	if (path[i - 1] != 'r' && path[i - 2] != 'e' && path[i - 3] != 'b' && path[i - 4] != '.')
		return (0);
	return (1);
}

// Frees the map array
void	ft_free_map(int height, t_map *map)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map->terrain[i]);
		i++;
	}
}

static int	ft_rectangular_check(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	if (map->height < 3 || map->width < 3 || map->width > MAX_WIDTH || map->height > MAX_HEIGHT)
		return (0);
	i = 1;
	while (map->height > i)
	{
		len = (int)ft_gnl_strlen(map->terrain[i], '\n');
		if (ft_chrstr(map->terrain[i], '\n'))
			len--;
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

// Returns 1 if the collectible, player and exit count meets the requirements
static int	ft_min_char_validator(t_map *map)
{
	int	valid_char_count;

	valid_char_count = 0;
	if (map->start_c != 1 || map->exit_c != 1)
		return (0);
	if (map->collectible_c < 1)
		return (0);
	valid_char_count += map->start_c;
	valid_char_count += map->exit_c;
	valid_char_count += map->space_c;
	valid_char_count += map->collectible_c;
	valid_char_count += map->wall_c;
	if ((valid_char_count != (map->height * map->width))
		|| valid_char_count < 15)
		return (0);
	return (1);
}

// int ft_map_wall_check
// walls must be all around the map
static int	ft_map_frame_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->terrain[0][i] != '1')
			return (0);
		if (map->terrain[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->terrain[i][0] != '1')
			return (0);
		if (map->terrain[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
