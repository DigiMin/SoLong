/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:39:53 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/18 09:41:02 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENUMS_H
# define GAME_ENUMS_H

typedef enum e_error
{
	INSTANCE_NOT_TOUCHED = -1,
	SUCCESS,
	FAILURE,
	MALLOC,
	OPEN,
	READ,
	INIT_FAILED,
	WRONG_EXTENSION,
	WRONG_MAP_SIZE,
	NOT_RECTANGULAR,
	NOT_FRAMED,
	WRONG_CHARS,
	NOT_PLAYABLE,
	NOT_NEAR,
	MLX_FAILURE,
	MLX_DRAW_FAILURE
}					t_error;

typedef enum e_axes
{
	X,
	Y
}					t_axes;

typedef enum e_anim_spec
{
	PLAYER_R,
	PLAYER_L,
	PLAYER_MR,
	PLAYER_ML,
	PLAYER_DEAD,
	ENEMY_CNTDWN,
	ENEMY_EXPLSN,
	ENEMY_NOT_SPAWNABLE
}					t_anim_spec;

#endif