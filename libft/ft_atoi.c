/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:34:13 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/01 16:35:46 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checksize(int result, int i, const char *str, int sign)
{
	unsigned long int	test;
	unsigned long int	pos_min;

	test = (long)result;
	pos_min = (long)INT_MAX + 1;
	if (sign == -1 && test * 10 + (str[i] - '0') > pos_min)
		return (1);
	if (sign == 1 && test * 10 + (str[i] - '0') > INT_MAX)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long		i;
	int					sign;
	int					result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] >= 48 && str[i + 1] <= 57))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_checksize(result, i, str, sign) == 1)
			return (0);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}
