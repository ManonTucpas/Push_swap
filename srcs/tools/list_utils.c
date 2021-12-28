/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:45:07 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 14:27:53 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	create_list(t_list **data, char *s, t_check *c)
{
	t_list	*elem;
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (d == NULL)
		return ;
	d->value = ft_atoi(s, c);
	elem = ft_lstnew(d);
	if (!(*data))
		*data = elem;
	else
		ft_lstadd_back(data, elem);
}

void	clear_list(t_list **list)
{
	t_list	*tmp;

	while (*list != NULL)
	{
		tmp = *list;
		if ((*list)->content)
			free(((t_data *)(*list)->content));
		*list = (*list)->next;
		free(tmp);
	}
}

t_list	*reverse_list(t_list **list)
{
	t_list	*cpy;
	t_list	*tmp;
	t_list	*tmp_bis;
	t_list	*to_free;

	tmp_bis = NULL;
	tmp = NULL;
	to_free = *list;
	cpy = *list;
	while (cpy != NULL)
	{
		tmp_bis = cpy->next;
		cpy->next = tmp;
		tmp = cpy;
		cpy = tmp_bis;
	}
	cpy = tmp;
	return (cpy);
}

int	is_sorted_list(t_list **list)
{
	t_list	*cpy;

	if (!(*list))
		return (-1);
	cpy = *list;
	while (cpy->next)
	{
		if (((t_data *)cpy->content)->value
			> ((t_data *)cpy->next->content)->value)
			return (-1);
		cpy = cpy->next;
	}
	return (0);
}

void	frees_ps(t_ps *ps)
{
	if (ps->a)
		clear_list(&ps->a);
	if (ps->b)
		clear_list(&ps->b);
	if (ps->rev)
		clear_list(&ps->rev);
	if (ps->rev_b)
		clear_list(&ps->rev_b);
	if (ps)
		free(ps);
}
