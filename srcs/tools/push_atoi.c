/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:00:18 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 12:08:36 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_checksize(int result, int i, const char *str, t_check *c)
{
	unsigned long int	test;
	unsigned long int	pos_min;

	test = (long)result;
	pos_min = (long)INT_MAX + 1;
	if (c->sign == -1 && test * 10 + (str[i] - '0') > pos_min)
	{
		c->error = -1;
		return (1);
	}
	if (c->sign == 1 && test * 10 + (str[i] - '0') > INT_MAX)
	{
		c->error = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, t_check *c)
{
	unsigned long		i;
	int					result;

	result = 0;
	c->sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		c->sign = c->sign * -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] >= 48 && str[i + 1] <= 57))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_checksize(result, i, str, c) == 1)
			return (0);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * c->sign);
}
