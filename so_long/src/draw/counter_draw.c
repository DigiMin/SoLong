/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:40:56 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 10:08:18 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_draw_numbers(t_graphics **graphics)
{
	char	*c;
	char	*full_path;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = ft_itoa(i);
		full_path = ft_multi_strjoin(3, "./graphics/UI/", c, ".png");
		if (!full_path)
			return (free(c), ft_mlx_error(graphics, MALLOC));
		(*graphics)->numbers[i] = ft_draw_number(graphics, full_path);
		if (!(*graphics)->numbers[i])
			return (ft_freen(2, c, full_path), ft_mlx_error(graphics,
					MLX_DRAW_FAILURE));
		ft_freen(2, c, full_path);
		i++;
	}
}
