/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/11 22:59:31 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_graphics *graphics = malloc(sizeof(t_graphics));

	graphics->map = ft_map_parser("./maps/test.ber");
	// graphics->map = ft_map_parser("./maps/small.ber");
	if (!graphics->map)
		printf("The map could not be used\n");
	else
		printf("The map is good as it is, YAY!\n");

	// Start mlx
	graphics->mlx = mlx_init(graphics->map->width * IMG_SIZE, graphics->map->height * IMG_SIZE, "Whole New World", false);
	if (!graphics->mlx)
	{
		mlx_terminate(graphics->mlx);
        error();
	}
	ft_set_map_img(graphics, graphics->map);
	graphics->anim = ft_init_game_anim(graphics);
	printf("ANIM inited in MAIN\n");
	graphics->map->collected = 0;
	graphics->can_move = 1;
	graphics->last_key = 'd';

	// int i;
	// i = 0;
	// while (i < ANIM_COUNT)
	// {
	// 	printf("Player_l[%d] z index: %d\n", i, graphics->player_l[i]->instances[0].z);
	// 	i++;
	// }
	// 	i = 0;
	// while (i < ANIM_COUNT)
	// {
	// 	printf("Player_r[%d] z index: %d\n", i, graphics->player_r[i]->instances[0].z);
	// 	i++;
	// }
	// 	i = 0;
	// while (i < ANIM_COUNT)
	// {
	// 	printf("Player_mr[%d] z index: %d\n", i, graphics->player_mr[i]->instances[0].z);
	// 	i++;
	// }
	// 	i = 0;
	// while (i < ANIM_COUNT)
	// {
	// 	printf("Player_ml[%d] z index: %d\n", i, graphics->player_ml[i]->instances[0].z);
	// 	i++;
	// }
	// printf("Tower z index: %d\n", graphics->exit->instances[0].z);
	// i=0;
	// while (i < graphics->map->enemy_c)
	// {
	// 	printf("Enemy[%d] z index: %d\n", i, graphics->enemy->instances[i].z);
	// 	i++;
	// }
	graphics->anim->z_exit = graphics->exit->instances[0].z;
	printf("Tower z index: %d\n", graphics->exit->instances[0].z);
	mlx_loop_hook(graphics->mlx, ft_hook, graphics);
	mlx_loop(graphics->mlx);

	// TODO: FREEEEEEEEEEEEEEEEEE
	// TODO: max width and max height of map
	// TODO: use ft_printf to print the moves
	// TODO: put the numbers on the screen to show the moves
	// TODO: refactor the code
	// TODO: check this function mlx_close_window(mlx_t* mlx) / mlx_delete_image(mlx, img);
	// // Optional, terminate will clean up any leftovers, this is just to demonstrate.
	// mlx_delete_texture(texture);
	mlx_terminate(graphics->mlx);
	return (EXIT_SUCCESS);
}