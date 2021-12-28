/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:03:12 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 17:03:16 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	up_find_chunk_values(t_list **list, int max)
{
	int		n;
	t_list	*cpy;

	cpy = *list;
	n = 0;
	while (cpy)
	{
		if (((t_data *)(cpy)->content)->index == max)
			return (n);
		cpy = cpy->next;
		n++;
	}
	return (-1);
}

static int	down_find_chunk_values(t_list **list, int max)
{
	int		n;
	t_list	*cpy;

	cpy = *list;
	n = 0;
	while (cpy)
	{
		if (((t_data *)(cpy)->content)->index == max)
			return (n);
		cpy = cpy->next;
		n++;
	}
	return (-1);
}

void	push_b_to_a_bis(t_ps *ps, t_check *c, int up, int down)
{
	int	i;

	i = 0;
	if (up > 0 && up <= down)
	{
		while (i < up)
		{
			ft_rotate(&ps->b, 'b', 1, c);
			i++;
		}
		ft_pa(ps, 1, c);
		return ;
	}
	else if (down > 0 && down < up)
	{
		while (i <= down)
		{
			ft_reverse_rotate(&ps->b, 'b', 1, c);
			i++;
		}
		ft_pa(ps, 1, c);
		return ;
	}
}

void	push_b_to_a(t_ps *ps, t_check *c, int up, int down)
{
	int	i;

	i = 0;
	if (up == 0)
	{
		ft_pa(ps, 1, c);
		return ;
	}
	else if (up == 1)
	{
		ft_swap(&ps->b, 'b', 1, c);
		ft_pa(ps, 1, c);
		return ;
	}
	else if (down == 0)
	{
		ft_reverse_rotate(&ps->b, 'b', 1, c);
		ft_pa(ps, 1, c);
		return ;
	}
	push_b_to_a_bis(ps, c, up, down);
}

void	sort_b(t_ps *ps, t_check *c)
{
	int	up;
	int	down;

	up = 0;
	down = 0;
	c->index = c->ac - 1;
	while (c->index != 0)
	{
		ft_list_duplicate(&ps->rev_b, ps->b);
		ps->rev_b = reverse_list(&ps->rev_b);
		up = up_find_chunk_values(&ps->b, c->index);
		down = down_find_chunk_values(&ps->rev_b, c->index);
		push_b_to_a(ps, c, up, down);
		clear_list(&ps->rev_b);
		c->index--;
	}
	ft_pa(ps, 1, c);
}
