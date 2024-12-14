/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mina <mina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:18:38 by honnguye          #+#    #+#             */
/*   Updated: 2024/12/12 12:47:34 by mina             ###   ########.fr       */
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
void	ft_set_assets(t_map *map);

// flood-fill funtions
void 	ft_free_matrix(char **arr, int height);
int		ft_allocate_visited(t_map *map);
void	ft_init_visited(t_map *map);
int		ft_is_playable(t_map *map);

// map load validate
t_map	*ft_init_map(char *path);
t_map	*ft_map_validator();
void 	ft_free_map(int height, t_map *map);

#endif