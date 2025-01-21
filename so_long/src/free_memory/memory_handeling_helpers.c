/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handeling_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:09:32 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:24 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/game.h"

void	ft_free_anim_array(t_anim **arr, int count)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < count && arr[i])
	{
		arr[i]->anim_images = NULL;
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_matrix(char **arr, int height)
{
	int	i;

	if (!arr || height <= 0)
		return ;
	i = 0;
	while (i < height)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_coords(t_coord **lst)
{
	t_coord	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->x = 0;
		(*lst)->y = 0;
		(*lst)->next = NULL;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	ft_freen(int32_t count, ...)
{
	va_list	args;
	int		i;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		free(va_arg(args, void *));
		i++;
	}
	va_end(args);
}
