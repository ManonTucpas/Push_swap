/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:46:15 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:59:23 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrr(t_ps *ps, int print, t_check *c)
{
	ft_reverse_rotate(&(ps->a), 'a', 0, c);
	ft_reverse_rotate(&(ps->b), 'b', 0, c);
	if (print == 1)
	{
		ft_putstr_fd("rrr\n", 1);
		c->count++;
		return ;
	}
	else
		return ;
}
