/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:40:10 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:58:12 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_char(char ab, t_check *c)
{
	if (ab == 'a')
	{
		ft_putstr_fd("rra\n", 1);
		c->count++;
	}
	else if (ab == 'b')
	{
		ft_putstr_fd("rrb\n", 1);
		c->count++;
	}
	return ;
}

void	ft_reverse_rotate(t_list **list, char ab, int print, t_check *c)
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list) || !(*list)->next)
		return ;
	new = NULL;
	tmp = NULL;
	tmp = *list;
	tmp2 = *list;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = ft_lstnew(tmp->content);
	ft_lstadd_front(list, new);
	tmp2->next = NULL;
	free(tmp);
	if (print == 1)
		print_char(ab, c);
	else
		return ;
}
