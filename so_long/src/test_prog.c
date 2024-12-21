/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:59 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/21 15:22:35 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static mlx_image_t* image;
// -----------------------------------------------------------------------------

// draw each asset to window
// 

void ft_animate(void *param)
{
	t_anim *player = param;

	if (player->sleep == 9)
	{
		if (player->anim_frame == player->anim_count - 1)
			player->anim_frame = 0;
		player->anim_frame++;
		player->sleep = 0;
	}
	player->sleep++;
	
	ft_switch_display(player);
}

void ft_move_player(t_graphics *graphics, char dia, int pix)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (dia == 'y')
			graphics->player[i]->instances[0].y += pix;
		else if (dia == 'x')
			graphics->player[i]->instances[0].x += pix;
		else
			return ;
		i++;
	}
}

bool	ft_check_wall(t_map *map, char ax, int poso, int posm)
{
	t_coord *walls;

	walls = map->walls;
	while (walls)
	{
		// up movement
		if (ax == 'y' && poso < (walls->y * 64 + 48) && poso > (walls->y * 64) && posm > (walls->x * 64) && posm < (walls->x * 64 + 64))
		{
			printf("Walls y: %d\n", walls->y * 64);
			return (false);
		}
		// down movement
		if (ax == 'y' && (poso + 64) > (walls->y * 64) && (poso + 64) < (walls->y * 64 + 64) && posm == (walls->x * 64) && posm < (walls->x * 64 + 64))
		{
			printf("Walls y: %d\n", walls->y * 64);
			return (false);
		}       
		// left movement
		if (ax == 'x' && poso < (walls->x * 64 + 56) && poso > (walls->x * 64) && posm == (walls->y * 64) && posm < (walls->y * 64 + 64))
		{
			printf("Walls x: %d\n", walls->x * 64);
			return (false);
		}
		// right movement
		if (ax == 'x' && (poso + 64) > (walls->x * 64) && (poso + 64) < (walls->x * 64 + 64) && posm == (walls->y * 64) && posm < (walls->y * 64 + 64))
		{
			printf("Walls x: %d\n", walls->x * 64);
			return (false);
		}
		walls = walls->next;
		printf("%c : %d\n", ax, poso);
	}
	return (true);
}

bool	ft_check_space(t_map *map, char ax, int posm, int poso)
{
	t_coord	*spaces = map->spaces;
	float	pom_coord = posm / 64;
	float	pos_coord = poso / 64;

	while (spaces)
	{
		if (ax == 'y' && (int)pom_coord >= spaces->y && (int)pos_coord == spaces->x)
			return (true);
		if (ax == 'x' && (int)pom_coord >= spaces->x && (int)pos_coord == spaces->y)
			return (true);
		spaces = spaces->next;
	}
	return (false);
}

void ft_hook(void* param)
{
	t_graphics *graphics = param;

	// TODO: create a function that sets every player image instance
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(graphics->mlx);
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_W) || mlx_is_key_down(graphics->mlx, MLX_KEY_UP))
	{
		if (ft_check_space(graphics->map, 'y', graphics->player[0]->instances[0].y - 4, graphics->player[0]->instances[0].x))
		// if (ft_check_wall(graphics->map, 'y', graphics->player[0]->instances[0].y - 4, graphics->player[0]->instances[0].x))
			ft_move_player(graphics, 'y', -4);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_S) || mlx_is_key_down(graphics->mlx, MLX_KEY_DOWN))
	{
		if (ft_check_space(graphics->map, 'y', graphics->player[0]->instances[0].y + 4, graphics->player[0]->instances[0].x))
		// if (ft_check_wall(graphics->map, 'y', graphics->player[0]->instances[0].y + 4, graphics->player[0]->instances[0].x))
			ft_move_player(graphics, 'y', +4);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_A) || mlx_is_key_down(graphics->mlx, MLX_KEY_LEFT))
	{
		if (ft_check_space(graphics->map, 'x', graphics->player[0]->instances[0].x - 4, graphics->player[0]->instances[0].y))
		// if (ft_check_wall(graphics->map, 'x', graphics->player[0]->instances[0].x - 4, graphics->player[0]->instances[0].y))
			ft_move_player(graphics, 'x', -4);
	}
	if (mlx_is_key_down(graphics->mlx, MLX_KEY_D) || mlx_is_key_down(graphics->mlx, MLX_KEY_RIGHT))
	{	
		if (ft_check_space(graphics->map, 'x', graphics->player[0]->instances[0].y + 4, graphics->player[0]->instances[0].y))
		// if (ft_check_wall(graphics->map, 'x', graphics->player[0]->instances[0].x + 4, graphics->player[0]->instances[0].y))
			ft_move_player(graphics, 'x', +4);
	}
	// if (mlx_is_key_down(graphics->mlx, MLX_KEY_SPACE))
	// 	ft_move_player(graphics, 'x', +4);
}

// -----------------------------------------------------------------------------

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	t_anim	*player;
	t_graphics *graphics = malloc(sizeof(t_graphics));
	
	graphics->map = ft_map_validator();
	if (!graphics->map)
		printf("The map could not be used\n");
	else
		printf("The map is good as it is, YAY!\n");

	// Start mlx
	graphics->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!graphics->mlx)
	{
		mlx_terminate(graphics->mlx);
        error();
	}
	
	player = ft_set_images(graphics, graphics->map);

	mlx_loop_hook(graphics->mlx, ft_animate, player);
	mlx_loop_hook(graphics->mlx, ft_hook, graphics);
	mlx_loop(graphics->mlx);

	// // Optional, terminate will clean up any leftovers, this is just to demonstrate.
	// mlx_delete_texture(texture);
	mlx_terminate(graphics->mlx);
	return (EXIT_SUCCESS);
}