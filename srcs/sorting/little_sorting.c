/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:37:24 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 16:26:37 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_list **list, t_check *c)
{
	int	a;
	int	b;
	int	d;

	a = ((t_data *)(*list)->content)->index;
	b = ((t_data *)(*list)->next->content)->index;
	d = ((t_data *)(*list)->next->next->content)->index;
	if (a < b && b > d && a < d)
	{
		ft_swap(list, 'a', 1, c);
		ft_rotate(list, 'a', 1, c);
	}
	if (a < b && b > d && a > d)
		ft_reverse_rotate(list, 'a', 1, c);
	if (a > b && b < d && d > a)
		ft_swap(list, 'a', 1, c);
	if (a > b && b < d && d < a)
		ft_rotate(list, 'a', 1, c);
	if (a > b && b > d)
	{
		ft_swap(list, 'a', 1, c);
		ft_reverse_rotate(list, 'a', 1, c);
	}
}

void	sort_two(t_list **ps, t_check *c)
{
	int	a;
	int	b;

	a = ((t_data *)(*ps)->content)->index;
	b = ((t_data *)(*ps)->next->content)->index;
	if (a > b)
		ft_swap(ps, 'a', 1, c);
	else
		return ;
}

void	sort_four(t_ps *ps, t_check *c)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (count != 0)
	{
		while (((t_data *)(ps->a)->content)->index != i)
		{
			ft_reverse_rotate(&ps->a, 'a', 1, c);
		}
		if (((t_data *)(ps->a)->content)->index == i)
		{
			ft_pb(ps, 1, c);
			count--;
		}
	}
	sort_three(&ps->a, c);
	ft_pa(ps, 1, c);
}

void	sort_five(t_ps *ps, t_check *c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	special_case(&ps->a, ps, c);
	special_case_two(&ps->a, ps, c);
	if (c->special == 1)
		return ;
	while (count < 2)
	{
		while (((t_data *)(ps->a)->content)->index != i)
			ft_reverse_rotate(&ps->a, 'a', 1, c);
		if (((t_data *)(ps->a)->content)->index == i)
		{
			ft_pb(ps, 1, c);
			count++;
			i++;
		}
	}
	sort_three(&ps->a, c);
	ft_pa(ps, 1, c);
	ft_pa(ps, 1, c);
}

void	get_algo(t_ps *ps, t_check *c)
{
	if (c->ac == 1)
		return ;
	else if (c->ac == 2)
		sort_two(&ps->a, c);
	else if (c->ac == 3)
		sort_three(&ps->a, c);
	else if (c->ac == 4)
		sort_four(ps, c);
	else if (c->ac == 5)
		sort_five(ps, c);
	else if (c->ac > 5 && c->ac <= 500)
		big_sort(ps, c);
	else
		return ;
}
