/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:51:01 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 11:25:33 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_appnd_coord(int x, int y, t_map **map)
{
	if ((*map)->terrain[y][x] == '1')
		ft_coord_add_back(&(*map)->walls, x, y);
	else if ((*map)->terrain[y][x] == '0')
		ft_coord_add_back(&(*map)->spaces, x, y);
	else if ((*map)->terrain[y][x] == 'C')
		ft_coord_add_back(&(*map)->collectibles, x, y);
	else if ((*map)->terrain[y][x] == 'P')
		ft_coord_add_back(&(*map)->start, x, y);
	else if ((*map)->terrain[y][x] == 'E')
		ft_coord_add_back(&(*map)->exit, x, y);
	ft_appnd_spaces(x, y, map);
	return (SUCCESS);
}

int	ft_appnd_spaces(int x, int y, t_map **map)
{
	if ((*map)->terrain[y][x] == 'C')
		ft_coord_add_back(&(*map)->spaces, x, y);
	else if ((*map)->terrain[y][x] == 'P')
		ft_coord_add_back(&(*map)->spaces, x, y);
	else if ((*map)->terrain[y][x] == 'E')
		ft_coord_add_back(&(*map)->spaces, x, y);
	return (SUCCESS);
}

void	ft_count_assets(int x, int y, t_map **map)
{
	if ((*map)->terrain[y][x] == '1')
		(*map)->wall_c++;
	else if ((*map)->terrain[y][x] == '0')
		(*map)->space_c++;
	else if ((*map)->terrain[y][x] == 'C')
		(*map)->collectible_c++;
	else if ((*map)->terrain[y][x] == 'P')
		(*map)->start_c++;
	else if ((*map)->terrain[y][x] == 'E')
		(*map)->exit_c++;
}
