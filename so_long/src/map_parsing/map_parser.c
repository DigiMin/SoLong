/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:29 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/22 15:25:15 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_min_char_validator(t_map *map);
static int	ft_map_frame_check(t_map *map);

// ---------- MAP VALIDATORS -----------

// map min height and width needs to be 4
// width must be the same on each line
int	ft_map_parser(t_map *map)
{
	int	ret;

	ret = SUCCESS;
	if (!map)
		return (FAILURE);
	ret = ft_map_frame_check(map);
	if (ret != SUCCESS)
		return (ret);
	ret = ft_min_char_validator(map);
	if (ret != SUCCESS)
		return (ret);
	ret = ft_is_playable(map);
	if (ret != SUCCESS)
		return (ret);
	return (ret);
}

// --------------------- MAP HELPERS --------------------------
int	ft_check_extension(char *path)
{
	size_t	i;

	i = ft_gnl_strlen(path, '\0');
	if (path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b' || path[i
			- 4] != '.')
		return (WRONG_EXTENSION);
	return (SUCCESS);
}

int	ft_rectangular_check(t_graphics **graphics, t_map *map)
{
	int	i;
	int	len;

	i = 1;
	while (map->height > i)
	{
		len = (int)ft_gnl_strlen(map->terrain[i], '\n');
		if (ft_chrstr(map->terrain[i], '\n'))
			len--;
		if (len != map->width)
			return (ft_map_error(graphics, NOT_RECTANGULAR, map->height),
				NOT_RECTANGULAR);
		i++;
	}
	return (SUCCESS);
}

// Returns 1 if the collectible, player and exit count meets the requirements
static int	ft_min_char_validator(t_map *map)
{
	int	valid_char_count;

	valid_char_count = 0;
	if (map->start_c != 1 || map->exit_c != 1)
		return (WRONG_CHARS);
	if (map->collectible_c < 1)
		return (WRONG_CHARS);
	valid_char_count += map->start_c;
	valid_char_count += map->exit_c;
	valid_char_count += map->space_c;
	valid_char_count += map->collectible_c;
	valid_char_count += map->wall_c;
	if ((valid_char_count != (map->height * map->width))
		|| valid_char_count < 15)
		return (WRONG_CHARS);
	return (SUCCESS);
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
			return (NOT_FRAMED);
		if (map->terrain[map->height - 1][i] != '1')
			return (NOT_FRAMED);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->terrain[i][0] != '1')
			return (NOT_FRAMED);
		if (map->terrain[i][map->width - 1] != '1')
			return (NOT_FRAMED);
		i++;
	}
	return (SUCCESS);
}
