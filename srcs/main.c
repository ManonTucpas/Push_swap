/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:44:10 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 16:24:51 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_index(int *tab, t_list **list, t_check *c)
{
	int		i;
	t_list	*cpy;

	cpy = *list;
	i = 0;
	while ((cpy) && i < c->ac)
	{
		i = 0;
		while (tab[i] != ((t_data *)(cpy)->content)->value)
			i++;
		if (tab[i] == ((t_data *)(cpy)->content)->value)
			((t_data *)(cpy)->content)->index = i;
		(cpy) = (cpy)->next;
	}
	free(tab);
}

void	get_index(t_list **list, t_check *c)
{
	int		*tab;
	int		i;
	t_list	*cpy;

	cpy = *list;
	i = 0;
	tab = (int *)malloc(sizeof(int) * c->ac);
	while (cpy && i < c->ac)
	{
		tab[i] = ((t_data *)(cpy)->content)->value;
		i++;
		cpy = cpy->next;
	}
	ft_sort_int_tab(tab, c->ac);
	i = 0;
	find_index(tab, list, c);
}

int	ps_malloc(t_ps *ps, int argc)
{
	if (!ps || argc < 2)
	{
		free(ps);
		return (-1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_list	*data;
	t_ps	*ps;
	t_check	c;

	data = NULL;
	ps = NULL;
	init_struct(&c, argc);
	parsing(argc, argv, &c);
	ps = (t_ps *)malloc(sizeof(t_ps));
	if (ps_malloc(ps, argc) == -1 || error(&c, ps) == -1)
		return (-1);
	while (argv[c.i])
	{
		create_list(&data, argv[c.i], &c);
		c.i++;
	}
	ps->a = data;
	init_ps(ps);
	if (check_sorted(ps) == -1)
		return (-1);
	get_index(&ps->a, &c);
	get_algo(ps, &c);
	frees_ps(ps);
	return (0);
}
