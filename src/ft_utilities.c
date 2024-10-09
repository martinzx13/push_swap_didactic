/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:32 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/19 10:38:11 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"


int	ft_check_place_b(t_stack *stack_b, int number_to_push)
{
	int		list_place;
	t_stack	*temp;

	list_place = 1;
	if (number_to_push > stack_b->number
		&& number_to_push < ft_lstlast(stack_b)->number)
		list_place = 0;
	else if (number_to_push > ft_find_max(stack_b)
		||number_to_push < ft_find_min(stack_b))
	{
		list_place = ft_find_index(stack_b, ft_find_max(stack_b));
	}
	else
	{
		temp = stack_b->next;
		while (stack_b->number < number_to_push
			|| temp->number > number_to_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			list_place++;
		}
	}
	return (list_place);
}

int	ft_check_place_a(t_stack *stack_a, int number_to_push)
{
	int		list_place;
	t_stack	*temp;

	list_place = 1;
	if (number_to_push < stack_a->number
		&& number_to_push > ft_lstlast(stack_a)->number)
		list_place = 0;
	else if (number_to_push > ft_find_max(stack_a)
		|| number_to_push < ft_find_min(stack_a))
		list_place = ft_find_index(stack_a, ft_find_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->number > number_to_push
			|| temp->number < number_to_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			list_place++;
		}
	}
	return (list_place);
}

int	ft_find_max(t_stack *stack_a)
{
	int	max;

	max = stack_a->number;
	while (stack_a)
	{
		if (stack_a->number > max)
			max = stack_a->number;
		stack_a = stack_a->next;
	}
	return (max);
}

int	ft_find_min(t_stack *stack_a)
{
	int	min;

	min = stack_a->number;
	while (stack_a)
	{
		if (stack_a->number < min)
			min = stack_a->number;
		stack_a = stack_a->next;
	}
	return (min);
}
