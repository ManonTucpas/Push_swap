/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:37:20 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:58:56 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_char(char ab, t_check *c)
{
	if (ab == 'a')
	{
		ft_putstr_fd("ra\n", 1);
		c->count++;
	}
	else if (ab == 'b')
	{
		ft_putstr_fd("rb\n", 1);
		c->count++;
	}
	return ;
}

void	ft_rotate(t_list **list, char ab, int print, t_check *c)
{
	t_list	*new;
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	new = ft_lstnew((*list)->content);
	tmp = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, new);
	free(tmp);
	if (print == 1)
		print_char(ab, c);
	else
		return ;
}
