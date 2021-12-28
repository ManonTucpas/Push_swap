/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorting_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:19:04 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 16:28:06 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	special_case(t_list **list, t_ps *ps, t_check *ch)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = ((t_data *)(*list)->content)->value;
	b = ((t_data *)(*list)->next->content)->value;
	c = ((t_data *)(*list)->next->next->content)->value;
	d = ((t_data *)(*list)->next->next->next->content)->value;
	e = ((t_data *)(*list)->next->next->next->next->content)->value;
	if (a > b && a > c && a > d && a < e && b < c && b < d
		&& b < e && c > d && c < e && d < e)
	{
		ft_reverse_rotate(list, 'a', 1, ch);
		ft_pb(ps, 1, ch);
		ft_pb(ps, 1, ch);
		ft_reverse_rotate(list, 'a', 1, ch);
		ft_swap(list, 'a', 1, ch);
		ft_pa(ps, 1, ch);
		ft_rotate(list, 'a', 1, ch);
		ft_pa(ps, 1, ch);
		ft_rotate(list, 'a', 1, ch);
		ch->special = 1;
	}
}

void	special_case_two(t_list **list, t_ps *ps, t_check *ch)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = ((t_data *)(*list)->content)->value;
	b = ((t_data *)(*list)->next->content)->value;
	c = ((t_data *)(*list)->next->next->content)->value;
	d = ((t_data *)(*list)->next->next->next->content)->value;
	e = ((t_data *)(*list)->next->next->next->next->content)->value;
	if (a > b && a > c && a > d && a > e && b < c && b < d
		&& b < e && c > d && c > e && d < e)
	{
		ft_pb(ps, 1, ch);
		ft_rotate(list, 'a', 1, ch);
		ft_pb(ps, 1, ch);
		ft_reverse_rotate(list, 'a', 1, ch);
		ft_pa(ps, 1, ch);
		ft_rotate(list, 'a', 1, ch);
		ft_pa(ps, 1, ch);
		ft_rotate(list, 'a', 1, ch);
		ch->special = 1;
	}
}
