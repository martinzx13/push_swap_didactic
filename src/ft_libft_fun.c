/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:37:30 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/21 09:40:08 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"


int	ft_find_index(t_stack *stack, int num)
{
	int	index;

	index = 0;
	while (stack->number != num)
	{
		index++;
		stack = stack->next;
	}
	stack->index = 0;
	return (index);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *list_a)
{
	size_t	i;

	i = 0;
	while (list_a)
	{
		(list_a) = (list_a)->next;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error_display();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > INT_MAX || (mod * i) < INT_MIN)
		ft_error_display();
	return (mod * i);
}
