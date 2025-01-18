/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 10:12:41 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

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

// free the visited matrix if something fails
void	ft_free_matrix(char **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
