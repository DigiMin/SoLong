/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:29 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/10 11:55:08 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// -------------------------------- MAP VALIDATORS ------------------------------- //

// TODO: check for map extensions and valid map names

// map min height and width needs to be 4
// width must be the same on each line
int	ft_map_validator()
{
	printf("Trying to initialize the map\n");
	if(!ft_init_map("./maps/test.ber"))
		return (0);
	printf("map initialized\n");
	if(!ft_rectangular_check())
		return (0);
	printf("rectangular checked\n");
	if(!ft_map_frame_check())
		return (0);
	printf("frame checked\n");
	if(!ft_min_char_validator())
		return(0);
	printf("chars checked\n");
	if(!ft_is_playable())
		return (0);
	printf("is playable\n");
	return (1);
}

int ft_rectangular_check()
{
	int	i;
	int len;
	
	if (game_map->height < 3 || game_map->width < 3)
		return (0);
	i = 1;
	while (game_map->height > i)
	{
		len = (int)ft_gnl_strlen(game_map->map_terrain[i], '\n');
		if (ft_chrstr(game_map->map_terrain[i], '\n'))
			len--;
		printf("terrain[%d]: %d\n",i, len);
		if(len != game_map->width)
			return (0);
		i++;
	}
	printf("Rectangular check OK\n");
	return (1);
}

// Returns 1 if the collectible, player and exit count meets the requirements
int ft_min_char_validator()
{
	int valid_char_count;

	valid_char_count = 0;
	if (game_map->start_c != 1 || game_map->exit_c != 1)
		return (0);
	if (game_map->collectible_c < 1)
		return (0);
	valid_char_count += game_map->start_c;
	valid_char_count += game_map->exit_c;
	valid_char_count += game_map->space_c;
	valid_char_count += game_map->collectible_c;
	valid_char_count += game_map->wall_c;
	if ((valid_char_count != game_map->height * game_map->width) && valid_char_count < 15)
		return (0);
	return (1);
}

// int ft_map_wall_check
// walls must be all around the map
int ft_map_frame_check()
{
	int	i;
	
	i = 0;
	printf("In map frame checker\n");
	printf("%p\n", game_map);
	printf("%p\n", game_map->map_terrain);
	printf("%p\n", game_map->map_terrain[0]);
	printf("%i\n", game_map->height);
	for(int k = 0; k < game_map->height; k++)
		printf("%s\n", game_map->map_terrain[k]);
	while (i < game_map->width)
	{
		if (game_map->map_terrain[0][i] != '1')
			return (0);
		if (game_map->map_terrain[game_map->height - 1][i] != '1')
			return (0);
		i++;
	}
	printf("UPPER AND LOWER WALLS OK\n");
	i = 0;
	while (i < game_map->height)
	{
		if (game_map->map_terrain[i][0] != '1')
			return (0);
		if (game_map->map_terrain[i][game_map->width - 1] != '1')
			return (0);
		i++;
	}
	printf("SIDE WALLS OK\n");
	return (1);
}

// -------------------------------- MAP HELPERS ------------------------------- //

// Read the map and init the variables
int ft_init_map(char *path)
{
	int i;
	int fd;
	printf("in map init\n");
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	game_map = malloc(sizeof(t_map));
	if (!game_map)
		return (0);
	game_map->map_terrain = malloc(sizeof(char *) * 20);
	while ((game_map->map_terrain[i] = get_next_line(fd)))
		i++;
	close(fd);
	game_map->height = i;
	printf("map height: %d\n", game_map->height);
	game_map->width = ft_gnl_strlen(game_map->map_terrain[0], '\0') - 1; // -1 for new line
	printf("map width: %d\n", game_map->width);
	game_map->start_c = ft_map_char_count('P');
	printf("map start count: %d\n", game_map->start_c);
	game_map->exit_c = ft_map_char_count('E');
	printf("map exit count: %d\n", game_map->exit_c);
	game_map->space_c = ft_map_char_count('0');
	printf("map spaces: %d\n", game_map->space_c);
	game_map->collectible_c = ft_map_char_count('C');
	printf("map collectibles: %d\n", game_map->collectible_c);
	printf("%s\n", game_map->map_terrain[0]);
	game_map->wall_c = ft_map_char_count('1');
	printf("map walls: %d\n", game_map->wall_c);

	return (1);
}

// Counts the number of character occurance in the array
int ft_map_char_count(char c)
{
	int he;
	int wi;
	int count;

	he = 0;
	count = 0;
	while (he < game_map->height)
	{
		wi = 0;
		while (wi < game_map->width)
		{
			if (game_map->map_terrain[he][wi] == c)
				count++;
			wi++;
		}
		he++;
	}
	return (count);
}

// Frees the map array
void ft_free_map(int height)
{
	int i = 0;
	while (i < height)
	{
		free(game_map->map_terrain[i]);
		i++;
	}
}

