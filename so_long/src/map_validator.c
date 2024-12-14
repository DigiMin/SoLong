/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:29 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/12 12:45:17 by mina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int ft_rectangular_check(t_map *map);
static int ft_min_char_validator(t_map *map);
static int ft_map_frame_check(t_map *map);

// -------------------------------- MAP VALIDATORS ------------------------------- //

// TODO: check for map extensions and valid map names

// map min height and width needs to be 4
// width must be the same on each line
t_map	*ft_map_validator()
{
	t_map	*map;
	map = ft_init_map("./maps/test.ber");
	if(!map)
		return (NULL);
	if(!ft_rectangular_check(map))
		return (NULL);
	if(!ft_map_frame_check(map))
		return (NULL);
	if(!ft_min_char_validator(map))
		return(NULL);
	if(!ft_is_playable(map))
		return (NULL);
	return (map);
}


// -------------------------------- MAP HELPERS ------------------------------- //

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

// Frees the map array
void ft_free_map(int height, t_map *map)
{
	int i = 0;
	while (i < height)
	{
		free(map->terrain[i]);
		i++;
	}
}

static int ft_rectangular_check(t_map *map)
{
	int	i;
	int len;
	i=0;
	if (map->height < 3 || map->width < 3)
		return (0);
	i = 1;
	while (map->height > i)
	{
		len = (int)ft_gnl_strlen(map->terrain[i], '\n');
		if (ft_chrstr(map->terrain[i], '\n'))
			len--;
		if(len != map->width)
			return (0);
		i++;
	}
	return (1);
}

// Returns 1 if the collectible, player and exit count meets the requirements
static int ft_min_char_validator(t_map *map)
{
	int valid_char_count;

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
	if ((valid_char_count != (map->height * map->width)) || valid_char_count < 15)
		return (0);
	return (1);
}

// int ft_map_wall_check
// walls must be all around the map
static int ft_map_frame_check(t_map *map)
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
