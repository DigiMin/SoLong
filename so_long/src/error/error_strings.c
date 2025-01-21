/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:46:27 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 11:05:57 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

char	*ft_error_str(t_error err)
{
	if (err == FAILURE)
		return ("OOPS! Something went wrong");
	if (err == MALLOC)
		return ("Memory allocation failed");
	if (err == OPEN)
		return ("Failed to open file");
	if (err == READ)
		return ("Failed to read file");
	if (err == INIT_FAILED)
		return ("Initialization failed");
	if (err == MLX_FAILURE)
		return ("Something in MLX failed");
	if (err == MLX_DRAW_FAILURE)
		return ("Failed to draw MLX image");
	return (ft_error_map_str(err));
}

char	*ft_error_map_str(t_error err)
{
	if (err == WRONG_ARGS)
		return ("Usage: ./so_long <map.ber>");
	if (err == WRONG_EXTENSION)
		return ("Wrong file extension");
	if (err == WRONG_MAP_SIZE)
		return ("Map size is too big");
	if (err == NOT_RECTANGULAR)
		return ("Map is not rectangular");
	if (err == NOT_FRAMED)
		return ("Map has to be framed by walls (1)");
	if (err == WRONG_CHARS)
		return ("Map contains wrong character count or type");
	if (err == NOT_PLAYABLE)
		return ("Map is not playable");
	if (err == SUCCESS)
		return ("Everything went smoothly");
	else
		return ("Undefined error");
}
