/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:42:38 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:59:36 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ss(t_ps *ps, int print, t_check *c)
{
	ft_swap(&(ps->a), 'a', 0, c);
	ft_swap(&(ps->b), 'b', 0, c);
	if (print == 1)
	{
		ft_putstr_fd("ss\n", 1);
		c->count++;
		return ;
	}
	else
		return ;
}
