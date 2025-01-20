/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 12:24:15 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_set_assets(t_map **map);
static int	ft_read_ber(t_map **map, char *path);
static int	ft_set_height(char *path, t_map **map);

// ---------------------- COORD SETTERS ------------------------------- //

// Read the map and init the variables
int	ft_init_map(t_map **map, char *path)
{
	int	ret;

	if (!map)
		return (INIT_FAILED);
	ret = SUCCESS;
	ft_init_map_vals(map);
	ret = ft_read_ber(map, path);
	if (ret != SUCCESS)
		return (ret);
	(*map)->width = ft_gnl_strlen((*map)->terrain[0], '\n') - 1;
	ret = ft_set_assets(map);
	if (ret != SUCCESS)
		return (ret);
	return (ret);
}

static int	ft_read_ber(t_map **map, char *path)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (OPEN);
	if (ft_set_height(path, map) != SUCCESS)
		return (OPEN);
	(*map)->terrain = malloc(sizeof(char *) * (*map)->height);
	(*map)->terrain[i] = get_next_line(fd);
	while (i < (*map)->height - 1)
	{
		i++;
		(*map)->terrain[i] = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

static int	ft_set_height(char *path, t_map **map)
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
	if (row)
		free(row);
	close(fd);
	(*map)->height = i;
	return (SUCCESS);
}

static int	ft_set_assets(t_map **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*map)->height)
	{
		x = 0;
		while (x < (*map)->width)
		{
			if (ft_appnd_coord(x, y, map) != SUCCESS)
				return (ft_free_map((*map)->height, map), MALLOC);
			ft_count_assets(x, y, map);
			x++;
		}
		y++;
	}
	if (ft_spawn_enemies(*map))
		return (FAILURE);
	return (SUCCESS);
}
