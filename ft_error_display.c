/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:24:31 by juan-pma          #+#    #+#             */
/*   Updated: 2023/08/21 10:27:50 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_display(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_check_sorted_list(t_stack *stack_a)
{
	int	num_sort;

	num_sort = stack_a->number;
	while (stack_a)
	{
		if (num_sort > stack_a->number)
			return (0);
		num_sort = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_check_dup(t_stack *list_a)
{
	t_stack	*temp_storage;

	while (list_a)
	{
		temp_storage = list_a->next;
		while (temp_storage)
		{
			if (list_a->number == temp_storage->number)
				return (1);
			temp_storage = temp_storage->next;
		}
		list_a = list_a->next;
	}
	return (0);
}
