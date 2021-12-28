/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:40:55 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 16:25:24 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_ps(t_ps *ps)
{
	ps->b = NULL;
	ps->rev = NULL;
	ps->rev_b = NULL;
}

void	init_struct(t_check *c, int ac)
{
	c->count = 0;
	c->error = 0;
	c->ac = 0;
	c->count = 0;
	c->sort_b = 0;
	c->index = 0;
	c->up = 0;
	c->down = 0;
	c->chunk = 0;
	c->ac = ac - 1;
	c->special = 0;
	c->i = 1;
}

static void	check_is_digit(char *str, t_check *c)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		c->error = -1;
		return ;
	}
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			c->error = -1;
			return ;
		}
		else
			i++;
	}
}

static int	check_twice(char **av, t_check *c)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i], c) == ft_atoi(av[j], c))
			{	
				c->error = -1;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	parsing(int argc, char **argv, t_check *c)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	j = 0;
	tab = (int *)malloc(sizeof(int) * c->ac);
	if (!tab)
		(c->error = -1);
	while (i < argc)
	{
		check_is_digit(argv[i], c);
		tab[j] = ft_atoi(argv[i], c);
		i++;
	}
	free(tab);
	check_twice((argv), c);
}
