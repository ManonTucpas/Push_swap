/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:43:41 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 14:26:38 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_char(t_check *c)
{
	ft_putstr_fd("pa\n", 1);
	c->count++;
	return ;
}

void	ft_pa(t_ps *ps, int print, t_check *c)
{
	ps->new = NULL;
	ps->tmp = NULL;
	if (!(ps->b))
		return ;
	if (ps->b->next == NULL)
	{
		ps->new = ps->b;
		ps->new->next = ps->a;
		ps->a = ps->new;
		ps->b = NULL;
		if (print == 1)
			print_char(c);
	}
	else
	{
		ps->tmp = ps->b;
		ps->new = ft_lstnew(ps->b->content);
		ps->b = ps->b->next;
		free(ps->tmp);
		ft_lstadd_front(&(ps->a), ps->new);
		if (print == 1)
			print_char(c);
	}
}
