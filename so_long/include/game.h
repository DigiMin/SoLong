/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/19 11:34:46 by honnguye         ###   ########.fr       */
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

typedef struct t_coord {
	int x;
	int y;
	struct t_coord *next;
} t_coord;

typedef struct t_map {
	int 	height;
	int 	width;
	char 	**terrain;
	char	**visited;
	int 	start_c;
	t_coord *start;
	int 	exit_c;
	t_coord *exit;
	int 	space_c;
	t_coord *spaces;
	int 	collectible_c;
	t_coord *collectibles;
	int 	wall_c;
	t_coord *walls;
	int 	collected;
} t_map;

typedef struct t_graphics {
	mlx_image_t **player;
	mlx_image_t *exit;
	mlx_image_t *space;
	mlx_image_t *collectable;
	mlx_image_t *wall;
	mlx_t *mlx;
	t_map *map;
} t_graphics;

typedef struct t_anim {
	int anim_count;
	int anim_frame;
	int sleep;
	char action;
	char direction;
	mlx_image_t **anim_images;
} t_anim;

t_coord	*ft_coord_new(int x, int y);
t_coord	*ft_coord_last(t_coord *lst);
void	ft_coords_clear(t_coord **lst);
void	ft_coord_add_back(t_coord **lst, t_coord *new);

// flood-fill funtions
void 	ft_free_matrix(char **arr, int height);
int		ft_is_playable(t_map *map);

// map load validate
t_map	*ft_init_map(char *path);
t_map	*ft_map_validator();
void 	ft_free_map(int height, t_map *map);


// draw functions
mlx_image_t    *ft_draw_asset(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t    *ft_draw_exit(mlx_t *mlx, char *path, t_coord *asset);
mlx_image_t    *ft_load_png(mlx_t *mlx, char *path);

t_anim	*ft_set_images(t_graphics *graphics, t_map *map);
void 	ft_switch_display(t_anim *asset);

#endif