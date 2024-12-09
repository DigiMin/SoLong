/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/08 22:57:46 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <MLX42/MLX42.h>
# include "get_next_line.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct t_map {
	int height;
	int width;
	char *map_terrain[30];
	int start_c;
	int exit_c;
	int space_c;
	int collectible_c;
	int wall_c;
	int is_playable;
} t_map;

typedef struct t_coord {
	int x;
	int y;
	struct t_coord *next;
} t_coord;


static mlx_image_t *image;
static mlx_t *mlx;
static t_coord *player;
static t_coord *fin;
static t_map *game_map;
static int collected = 0;

// used for visited - now idk
t_coord	*ft_coord_new(int x, int y);
t_coord	*ft_coord_last(t_coord *lst);
void	ft_coords_clear(t_coord **lst);
void	ft_coord_add_back(t_coord **lst, t_coord *new);
void 	ft_find_set_coords(t_coord *sprite, char c);

void 	ft_update_player_pos(int x, int y);

#endif