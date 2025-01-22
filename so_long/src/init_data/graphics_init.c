/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/22 15:29:47 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_init_graphics(t_graphics **graphics, char *path)
{
	int	ret;

	(*graphics)->map = malloc(sizeof(t_map));
	if (!(*graphics)->map)
		return (ft_map_error(graphics, MALLOC, 0), MALLOC);
	if (ft_init_map(graphics, &((*graphics)->map), path) != SUCCESS)
		return (ft_map_error(graphics, INIT_FAILED, (*graphics)->map->height),
			INIT_FAILED);
	ret = ft_map_parser((*graphics)->map);
	if (ret != SUCCESS)
		return (ft_map_error(graphics, ret, (*graphics)->map->height), ret);
	(*graphics)->mlx = mlx_init((*graphics)->map->width * IMG_SIZE,
			(*graphics)->map->height * IMG_SIZE, NAME, false);
	if ((*graphics)->mlx == NULL)
		return (ft_map_error(graphics, MLX_FAILURE, (*graphics)->map->height),
			MLX_FAILURE);
	ft_set_map_img(graphics, (*graphics)->map);
	ft_init_graphics_vals(graphics);
	return (SUCCESS);
}
