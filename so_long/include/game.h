/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/15 10:48:28 by honnguye         ###   ########.fr       */
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
void    ft_draw_map(mlx_t *mlx, t_map *map,char *path, t_coord *asset);
mlx_image_t    *ft_load_png(mlx_t *mlx, char *path);

#endif