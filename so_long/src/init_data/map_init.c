/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:26:43 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 23:58:42 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_set_assets(t_graphics **graphics, t_map **map);
static int	ft_read_ber(t_graphics **graphics, t_map **map, char *path);
static int	ft_set_height(t_graphics **graphics, char *path, t_map **map);

// ---------------------- COORD SETTERS ------------------------------- //

// Read the map and init the variables
int	ft_init_map(t_graphics **graphics, t_map **map, char *path)
{
	int	ret;

	if (!map)
		return (INIT_FAILED);
	ret = SUCCESS;
	ft_init_map_vals(map);
	ret = ft_read_ber(graphics, map, path);
	if (ret != SUCCESS)
		return (ft_map_error(graphics, ret, 0), ret);
	ret = ft_size_check(graphics, *map);
	if (ret != SUCCESS)
		return (ft_map_error(graphics, ret, (*map)->height), ret);
	ret = ft_rectangular_check(graphics, *map);
	if (ret != SUCCESS)
		return (ft_map_error(graphics, ret, (*map)->height), ret);
	ret = ft_set_assets(graphics, map);
	if (ret != SUCCESS)
		return (ft_map_error(graphics, ret, (*map)->height), ret);
	return (ret);
}

int	ft_size_check(t_graphics **graphics, t_map *map)
{
	if (map->height < 3 || map->height > MAX_HEIGHT || map->width < 3
		|| map->width > MAX_WIDTH)
		return (ft_map_error(graphics, WRONG_MAP_SIZE, map->height),
			WRONG_MAP_SIZE);
	return (SUCCESS);
}

static int	ft_read_ber(t_graphics **graphics, t_map **map, char *path)
{
	int	i;
	int	fd;

	i = 0;
	if (ft_set_height(graphics, path, map) != SUCCESS)
		return (ft_map_error(graphics, OPEN, 0), OPEN);
	(*map)->terrain = malloc(sizeof(char *) * (*map)->height);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_map_error(graphics, OPEN, 0), OPEN);
	(*map)->terrain[i] = get_next_line(fd);
	if (!(*map)->terrain[i])
		return (ft_map_error(graphics, MALLOC, i), MALLOC);
	while (i < (*map)->height - 1 && (*map)->terrain[i])
	{
		i++;
		(*map)->terrain[i] = get_next_line(fd);
		if (!(*map)->terrain[i])
			return (ft_map_error(graphics, MALLOC, i), MALLOC);
	}
	(*map)->width = ft_gnl_strlen((*map)->terrain[0], '\n') - 1;
	close(fd);
	return (SUCCESS);
}

static int	ft_set_height(t_graphics **graphics, char *path, t_map **map)
{
	int		i;
	int		fd;
	char	*row;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (OPEN);
	row = get_next_line(fd);
	if (!row)
		return (WRONG_MAP_SIZE);
	while (row)
	{
		i++;
		free(row);
		row = get_next_line(fd);
		if (!row)
			break ;
	}
	if (row)
		free(row);
	close(fd);
	(*map)->height = i;
	return (SUCCESS);
}

static int	ft_set_assets(t_graphics **graphics, t_map **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*map)->height)
	{
		x = 0;
		while (x < (*map)->width)
		{
			if (ft_appnd_coord(graphics, x, y, map) != SUCCESS)
				return (ft_free_map((*map)->height, map), MALLOC);
			ft_count_assets(x, y, map);
			x++;
		}
		y++;
	}
	if (ft_spawn_enemies(graphics, *map))
		return (ft_free_map((*map)->height, map), INIT_FAILED);
	return (SUCCESS);
}
