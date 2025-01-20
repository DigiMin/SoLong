/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:25:49 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 11:38:07 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	ft_init_graphics(t_graphics **graphics, char *path)
{
	int ret;

	ret = 0;
	(*graphics)->map = malloc(sizeof(t_map));
	// printf("GRAPHICS P:%p\n", graphics->map);
	if (!(*graphics)->map)
		return (MALLOC);
	ret = ft_init_map(&((*graphics)->map), path);
	if (ret != SUCCESS)
		return (INIT_FAILED);
	ret = ft_map_parser((*graphics)->map);
	// printf("MAP PARSER RET: %d\n", ret);
	if (ret != SUCCESS)
		return (ft_free_map((*graphics)->map->height, &(*graphics)->map), INIT_FAILED);
	(*graphics)->mlx = mlx_init((*graphics)->map->width * IMG_SIZE,
			(*graphics)->map->height * IMG_SIZE, NAME, false);
	if ((*graphics)->mlx == NULL)
		return (ft_free_map((*graphics)->map->height, &(*graphics)->map), MLX_FAILURE);
	ft_set_map_img(graphics, (*graphics)->map);
	(*graphics)->anim = ft_set_player_anim(graphics);
	(*graphics)->map->collected = 0;
	(*graphics)->can_move = 1;
	(*graphics)->last_anim_dir = PLAYER_MR;
	(*graphics)->anim->z_exit = (*graphics)->exit->instances[0].z;
	printf("INIT GRAPHICS SUCCESS\n");
	return (SUCCESS);
}
