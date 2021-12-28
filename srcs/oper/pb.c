/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:44:02 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:56:59 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_char(t_check *c)
{
	ft_putstr_fd("pb\n", 1);
	c->count++;
	return ;
}

void	ft_pb(t_ps *ps, int print, t_check *c)
{
	ps->new = NULL;
	ps->tmp = NULL;
	if (!(ps->a))
		return ;
	if (ps->a->next == NULL)
	{
		ps->new = ps->a;
		ps->new->next = ps->b;
		ps->b = ps->new;
		ps->a = NULL;
		if (print == 1)
			print_char(c);
	}
	else
	{
		ps->tmp = ps->a;
		ps->new = ft_lstnew(ps->a->content);
		ps->a = ps->a->next;
		free(ps->tmp);
		ft_lstadd_front(&(ps->b), ps->new);
		if (print == 1)
			print_char(c);
	}
}
