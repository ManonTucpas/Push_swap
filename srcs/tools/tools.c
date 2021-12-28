/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:23:44 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 11:25:42 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	error(t_check *c, t_ps *ps)
{
	if (c->error == -1)
	{
		free(ps);
		printf("Error\n");
		return (-1);
	}
	return (0);
}

int	check_sorted(t_ps *ps)
{
	if (!is_sorted_list(&ps->a))
	{
		clear_list(&ps->a);
		free(ps);
		return (-1);
	}
	else
		return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	get_chunk(t_check *c)
{
	int	chunk_size;

	if (c->ac >= 250)
		chunk_size = (c->ac / 10);
	if (c->ac >= 100 && c->ac < 250)
		chunk_size = (c->ac / 6);
	if (c->ac < 100 && c->ac > 10)
		chunk_size = (c->ac / 3);
	if (c->ac <= 10)
		chunk_size = (c->ac / 2);
	c->chunk = chunk_size;
	return (chunk_size);
}
