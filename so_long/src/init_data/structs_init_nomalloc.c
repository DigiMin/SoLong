/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init_nomalloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:06 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/17 10:17:17 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/game.h"

void	ft_init_anim_img(t_anim *anim)
{
	anim->anim_count = ANIM_COUNT;
	anim->anim_frame = 0;
	anim->sleep = 0;
	anim->anim_speed = ANIM_SPEED;
	anim->enabled = 0;
}