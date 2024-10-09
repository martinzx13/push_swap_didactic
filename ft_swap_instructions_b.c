/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:19:33 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/23 15:40:55 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sub_rrb(t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_list;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	temp_list = (*stack_a);
	(*stack_a) = ft_lstlast(*stack_a);
	(*stack_a)->next = temp_list;
	(*stack_a) = temp_list->next;
	temp_list->next = NULL;
	temp_list = (*stack_b);
	(*stack_b) = ft_lstlast(*stack_b);
	(*stack_b)->next = temp_list;
	(*stack_b) = temp_list->next;
	temp_list->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_rrb(t_stack **stack_b)
{
	t_stack	*temp_stack;
	int		i;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	i = 0;
	temp_stack = (*stack_b);
	while ((*stack_b)->next)
	{
		i++;
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b)->next = temp_stack;
	while (i > 1)
	{
		temp_stack = temp_stack->next;
		i--;
	}
	temp_stack->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_rotate_rb(t_stack **stack_b)
{
	t_stack	*temp_value;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp_value = (*stack_b);
	(*stack_b) = ft_lstlast(*stack_b);
	(*stack_b)->next = temp_value;
	(*stack_b) = temp_value->next;
	temp_value->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_stack;

	if (!(*stack_a))
		return ;
	temp_stack = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = temp_stack;
	write(1, "pb\n", 3);
}
