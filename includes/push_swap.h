/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:02:18 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/09/02 16:28:43 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	int	value;
	int	index;
}				t_data;

typedef struct s_check
{
	int	error;
	int	ac;
	int	count;
	int	sort_b;
	int	index;
	int	up;
	int	down;
	int	chunk;
	int	sign;
	int	i;
	int	special;
}				t_check;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	t_list	*rev;
	t_list	*rev_b;
	t_list	*tmp;
	t_list	*new;
}				t_ps;

/**
 * UTILS
 **/
void	ft_sort_int_tab(int *tab, int size);
int		ft_atoi(const char *str, t_check *c);
void	init_struct(t_check *c, int ac);
void	get_index(t_list **list, t_check *c);
int		ft_list_duplicate(t_list **dst_list, t_list *src_list);
int		is_sorted_list(t_list **list);
void	init_ps(t_ps *ps);
int		check_sorted(t_ps *ps);
int		get_chunk(t_check *c);

/**
 * LIST UTILS
**/
void	print_list(t_list *list);
void	create_list(t_list **data, char *s, t_check *c);
t_list	*reverse_list(t_list **list);
t_list	*cpy_list(t_list *src);
void	ft_list_push_back(t_list **begin_list, void *data);
void	clear_list(t_list **list);
void	frees_ps(t_ps *ps);

/**
 *  PARSING
**/
void	parsing(int argc, char **argv, t_check *c);
int		error(t_check *c, t_ps *ps);

/**
 * OPERATIONS
**/
void	ft_swap(t_list **list, char ab, int print, t_check *c);
void	ft_rotate(t_list **list, char ab, int print, t_check *c);
void	ft_reverse_rotate(t_list **list, char ab, int print, t_check *c);
void	ft_ss(t_ps *ps, int print, t_check *c);
void	ft_rr(t_ps *ps, int print, t_check *c);
void	ft_rrr(t_ps *ps, int print, t_check *c);
void	ft_pa(t_ps *psa, int print, t_check *c);
void	ft_pb(t_ps *psa, int print, t_check *c);

/**
 * PUSHSWAP
**/
void	get_algo(t_ps *ps, t_check *c);
void	sort_three(t_list **list, t_check *c);
void	sort_two(t_list **ps, t_check *c);
void	sort_five(t_ps *ps, t_check *c);
void	sort_four(t_ps *ps, t_check *c);
void	big_sort(t_ps *ps, t_check *c);
void	push_chunk_in_stack(t_ps *ps, t_check *c, int up, int down);
void	sort_b(t_ps *ps, t_check *c);
void	special_case(t_list **list, t_ps *ps, t_check *ch);
void	special_case_two(t_list **list, t_ps *ps, t_check *ch);

#endif