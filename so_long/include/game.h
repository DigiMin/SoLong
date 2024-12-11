/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/10 12:16:13 by honnguye         ###   ########.fr       */
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
	char **map_terrain;
	int start_c;
	int exit_c;
	int space_c;
	int collectible_c;
	int wall_c;
} t_map;

typedef struct t_coord {
	int x;
	int y;
	struct t_coord *next;
} t_coord;


static mlx_image_t *image;
static mlx_t *mlx;
static t_coord *player;
static t_map *game_map;
static int collected = 0;

// used for visited - now idk
t_coord	*ft_coord_new(int x, int y);
t_coord	*ft_coord_last(t_coord *lst);
void	ft_coords_clear(t_coord **lst);
void	ft_coord_add_back(t_coord **lst, t_coord *new);
void 	ft_find_set_coords(t_coord *sprite, char c);

// player settings
void 	ft_player_init();
void 	ft_update_player_pos(int x, int y);

// flood-fill funtions
void 	ft_free_matrix(char **arr, int height);
int		ft_allocate_visited();
void	ft_init_visited();
void	ft_flood_fill(int x, int y);
int		ft_is_playable();

// map load validate
void 	ft_free_map(int height);
int		ft_map_char_count(char c);
int		ft_init_map(char *path);
int		ft_map_frame_check();
int		ft_min_char_validator();
int		ft_rectangular_check();
int	ft_map_validator();

#endif