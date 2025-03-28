/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:08:51 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:10 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static int	ft_set_pimage_coord(t_graphics *graphics, int x, int y);
static int	ft_is_space(t_graphics *graphics, int xm, int ym);
static void	ft_print_info_to_terminal(t_graphics *graphics);

void	ft_move_player(t_graphics *graphics, t_axes dia, int pix)
{
	int	xm;
	int	ym;

	ym = graphics->player_r[0]->instances[0].y;
	xm = graphics->player_r[0]->instances[0].x;
	if (dia == X)
		xm += pix;
	else if (dia == Y)
	{
		ft_animate(graphics->anim, graphics->last_anim_dir);
		ym += pix;
	}
	if (ft_is_space(graphics, xm, ym) != SUCCESS)
		return ;
	ft_switch_exit_z(&graphics);
	ft_set_pimage_coord(graphics, xm, ym);
	ft_switch_counter(graphics->anim->numbers, ++graphics->map->move_c);
	ft_print_info_to_terminal(graphics);
}

static void	ft_print_info_to_terminal(t_graphics *graphics)
{
	int	e_count;
	int	i;

	e_count = 0;
	i = 0;
	while (i < graphics->map->enemy_c)
	{
		if (graphics->anim->enemy_loops[i] > 0)
			e_count++;
		i++;
	}
	ft_printf("\033[H\033[JMove count: %d\n", graphics->map->move_c);
	ft_printf("Collected: %d/%d\n", graphics->map->collected,
		graphics->map->collectible_c);
	ft_printf("Enemies encountered: %d/%d\n", e_count, graphics->map->enemy_c);
}

static int	ft_set_pimage_coord(t_graphics *graphics, int x, int y)
{
	int	i;

	i = 0;
	while (i < ANIM_COUNT)
	{
		graphics->player_r[i]->instances[0].x = x;
		graphics->player_r[i]->instances[0].y = y;
		graphics->player_l[i]->instances[0].x = x;
		graphics->player_l[i]->instances[0].y = y;
		graphics->player_mr[i]->instances[0].x = x;
		graphics->player_mr[i]->instances[0].y = y;
		graphics->player_ml[i]->instances[0].x = x;
		graphics->player_ml[i]->instances[0].y = y;
		graphics->player_dead[i]->instances[0].x = x;
		graphics->player_dead[i]->instances[0].y = y;
		i++;
	}
	return (SUCCESS);
}

static int	ft_is_space(t_graphics *graphics, int xm, int ym)
{
	int	x[2];
	int	y[2];

	x[0] = (xm + OFFSET) / IMG_SIZE;
	y[0] = (ym + OSET) / IMG_SIZE;
	x[1] = (xm + IMG_SIZE - OFFSET) / IMG_SIZE;
	y[1] = (ym + IMG_SIZE - 1) / IMG_SIZE;
	if (graphics->map->visited[y[0]][x[0]] != '0'
		&& graphics->map->visited[y[1]][x[1]] != '0'
		&& graphics->map->visited[y[1]][x[0]] != '0'
		&& graphics->map->visited[y[0]][x[1]] != '0')
		return (SUCCESS);
	return (FAILURE);
}
