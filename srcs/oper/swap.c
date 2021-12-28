/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:41:26 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 13:00:00 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_list **list, char ab, int print, t_check *c)
{
	t_list	*elem;

	if (!(*list) || !(*list)->next)
		return ;
	elem = (*list)->next;
	(*list)->next = (*list)->next->next;
	elem->next = *list;
	*list = elem;
	if (print == 1)
	{
		if (ab == 'a')
		{
			ft_putstr_fd("sa\n", 1);
			c->count++;
		}
		else if (ab == 'b')
		{
			ft_putstr_fd("sb\n", 1);
			c->count++;
		}
		return ;
	}
	else
		return ;
}
