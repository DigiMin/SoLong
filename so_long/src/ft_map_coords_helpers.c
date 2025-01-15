/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_coords_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:31:54 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/15 20:54:49 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_coord_add_back(t_coord **lst, t_coord *new)
{
	t_coord	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_coord_last(*lst);
	last->next = new;
}

void	ft_coords_clear(t_coord **lst)
{
	t_coord	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->x = 0;
		(*lst)->y = 0;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

t_coord	*ft_coord_last(t_coord *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_coord	*ft_coord_new(int x, int y)
{
	t_coord	*new;

	new = malloc(sizeof(t_coord));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

t_coord	*ft_get_nth_coord(t_coord *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

// void	ft_coord_del_one(t_coord **lst, int n)
// {
// 	t_coord	*tmp;
// 	t_coord	*prev;
// 	int		i;

// 	if (!lst)
// 		return ;
// 	i = 0;
// 	tmp = *lst;
// 	prev = NULL;
// 	while (i < n)
// 	{
// 		prev = tmp;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	if (prev)
// 		prev->next = tmp->next;
// 	else
// 		*lst = tmp->next;
// 	free(tmp);
// }
