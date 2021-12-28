/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:02:56 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:41:53 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	up_find_chunk_values(t_list **list, int begin, int end)
{
	int		n;
	t_list	*cpy;

	cpy = *list;
	n = 0;
	while (cpy)
	{
		if (((t_data *)(cpy)->content)->index >= begin
			&& ((t_data *)(cpy)->content)->index < end)
			return (n);
		cpy = cpy->next;
		n++;
	}
	return (-1);
}

static int	down_find_chunk_values(t_list **list, int begin, int end)
{
	int		n;
	t_list	*cpy;

	cpy = *list;
	n = 0;
	while (cpy)
	{
		if (((t_data *)(cpy)->content)->index >= begin
			&& ((t_data *)(cpy)->content)->index < end)
			return (n);
		cpy = cpy->next;
		n++;
	}
	return (-1);
}

void	push_chunk_in_stack_bis(t_ps *ps, t_check *c, int up, int down)
{
	int	i;

	i = 0;
	if (down > 0 && down < up)
	{
		while (i <= down)
		{
			ft_reverse_rotate(&ps->a, 'a', 1, c);
			i++;
		}
		ft_pb(ps, 1, c);
		return ;
	}
}

void	push_chunk_in_stack(t_ps *ps, t_check *c, int up, int down)
{
	int	i;

	i = 0;
	if (up == 0)
	{
		ft_pb(ps, 1, c);
		return ;
	}
	else if (up > 0 && up <= down)
	{
		while (i < up)
		{
			ft_rotate(&ps->a, 'a', 1, c);
			i++;
		}
		ft_pb(ps, 1, c);
		return ;
	}
	if (down == 0)
	{
		ft_reverse_rotate(&ps->a, 'a', 1, c);
		ft_pb(ps, 1, c);
		return ;
	}
	push_chunk_in_stack_bis(ps, c, up, down);
}

void	big_sort(t_ps *ps, t_check *c)
{
	int	chunk_size;
	int	begin;
	int	up;
	int	down;
	int	i;

	chunk_size = get_chunk(c);
	begin = 0;
	while (ps->a)
	{
		i = c->chunk;
		while (i >= 0)
		{	
			ft_list_duplicate(&ps->rev, ps->a);
			ps->rev = reverse_list(&ps->rev);
			up = up_find_chunk_values(&ps->a, begin, chunk_size);
			down = down_find_chunk_values(&ps->rev, begin, chunk_size);
			push_chunk_in_stack(ps, c, up, down);
			clear_list(&ps->rev);
			i--;
		}
		begin += c->chunk;
		chunk_size += c->chunk;
	}
	sort_b(ps, c);
}
