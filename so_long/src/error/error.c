/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:51:47 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:50 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_terminate_game(t_graphics **graphics, t_error err)
{
	if (graphics)
		ft_free_graphics(graphics);
	exit(err);
}

void	ft_error(t_graphics **graphics, t_error err)
{
	if (err != SUCCESS)
	{
		ft_printf("Error\n%s\n", ft_error_str(err));
		if (graphics)
			ft_free_graphics(graphics);
		exit(err);
	}
	else
		ft_printf("Success\n%s\n", ft_error_str(err));
	exit(err);
}

void	ft_map_error(t_graphics **graphics, t_error err)
{
	if (err != SUCCESS)
	{
		ft_printf("Error\n%s\n", ft_error_str(err));
		if ((*graphics)->map)
			ft_free_map((*graphics)->map->height, &(*graphics)->map);
		exit(err);
	}
	else
		ft_printf("Success\n%s\n", ft_error_str(err));
	exit(err);
}

void	ft_mlx_error(t_graphics **graphics, t_error err)
{
	if (err != SUCCESS)
	{
		ft_printf("Error\n%s\n", ft_error_str(err));
		if ((*graphics)->map)
			ft_free_map((*graphics)->map->height, &(*graphics)->map);
		if ((*graphics)->mlx)
			mlx_terminate((*graphics)->mlx);
		exit(err);
	}
	else
		ft_printf("Success\n%s\n", ft_error_str(err));
	exit(err);
}
