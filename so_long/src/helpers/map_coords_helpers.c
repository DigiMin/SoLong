/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coords_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honnguye <honnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:31:54 by honnguye          #+#    #+#             */
/*   Updated: 2025/01/20 11:23:52 by honnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	ft_coord_add_back(t_coord **lst, int x, int y)
{
	t_coord	*last;
	t_coord	*head;
	t_coord	*new;

	new = ft_coord_new(x, y);
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	last = ft_coord_last(head);
	last->next = new;
}

t_coord	*ft_coord_last(t_coord *lst)
{
	t_coord	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
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
	t_coord	*node;

	i = 0;
	if (!lst)
		return (NULL);
	node = lst;
	while (i < n)
	{
		node = node->next;
		i++;
	}
	return (node);
}
