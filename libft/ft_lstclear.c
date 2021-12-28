/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:54:39 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 16:37:01 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst)
	{
		ptr = *lst;
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = ptr;
		}
	}
}
