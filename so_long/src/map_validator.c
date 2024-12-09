/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:29 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 23:02:13 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void ft_free_map(int height);
int ft_map_char_count(char c);

// -------------------------------- MAP VALIDATORS ------------------------------- //

// map min height and width needs to be 4
// width must be the same on each line
int ft_rectangular_check(char *path)
{
	int	i;
	
	if (game_map->height < 3 || game_map->width < 3)
	{
		ft_free_map(game_map->height - 1);
		return (0);
	}
	i = 1;
	while (game_map->height > i)
	{
		if(ft_gnl_strlen(game_map->map_terrain[i], '\n') != game_map->width)
		{
			ft_free_map(game_map->height - 1);
			return (0);
		}
		i++;
	}
	return (1);
	// TODO: move to seperate function valid characters checker mapsize & min character count
	if ((game_map->start_c + game_map->exit_c + game_map->space_c + game_map->collectible_c + game_map->wall_c \
	!= game_map->height * game_map->width) && game_map->height * game_map->width < 15)
	{
		ft_free_map(game_map->height - 1);
		return (0);
	}
}

// Returns 1 if the collectible, player and exit count meets the requirements
int ft_min_char_validator()
{
	if (game_map->start_c != 1 || game_map->exit_c != 1)
		return (0);
	if (game_map->collectible_c < 1)
		return (0);
	return (1);
}

// int ft_map_wall_check
// walls must be all around the map
int ft_map_frame_check()
{
	int	i;
	
	i = 0;
	while (i < game_map->width)
	{
		if (game_map->map_terrain[0][i] != '1')
			return (0);
		if (game_map->map_terrain[game_map->height - 1][i] != '1')
			return (0);
	}
	i = 0;
	while (i < game_map->height)
	{
		if (game_map->map_terrain[i][0] != '1')
			return (0);
		if (game_map->map_terrain[i][game_map->width - 1] != '1')
			return (0);
	}
	return (1);
}




// -------------------------------- MAP HELPERS ------------------------------- //

// Read the map and init the variables
int ft_init_map(char *path)
{
	int i;
	int fd;

	i = 0;
	fd == open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (game_map->map_terrain[i] = get_next_line(fd))
		i++;
	game_map->height = i;
	game_map->width = ft_gnl_strlen(game_map->map_terrain[0], '\0');
	game_map->start_c = ft_map_char_count('P');
	game_map->exit_c = ft_map_char_count('E');
	game_map->space_c = ft_map_char_count('0');
	game_map->collectible_c = ft_map_char_count('C');
	game_map->wall_c = ft_map_char_count('1');
	game_map->is_playable = 0;
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

