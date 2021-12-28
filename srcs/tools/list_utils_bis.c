/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:18:12 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:18:29 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = NULL;
	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = data;
	elem->next = NULL;
	return (elem);
}

t_data	*ft_data_duplicate(t_data *data)
{
	t_data	*new_data;

	if (!data)
		return (NULL);
	new_data = malloc(sizeof(t_data));
	if (!new_data)
		return (NULL);
	new_data->value = data->value;
	new_data->index = data->index;
	return (new_data);
}

int	ft_list_duplicate(t_list **dst_list, t_list *src_list)
{
	t_data	*tmp;

	*dst_list = NULL;
	if (!src_list)
		return (0);
	while (src_list)
	{
		tmp = ft_data_duplicate((t_data *)src_list->content);
		if (tmp == NULL)
			return (-1);
		ft_list_push_back(dst_list, tmp);
		if (*dst_list == NULL)
			return (-1);
		src_list = src_list->next;
	}
	return (0);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = NULL;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
}
