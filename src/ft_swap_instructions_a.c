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

#include "../library/push_swap.h"


void	ft_reverse_rotate_rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_sub_rrb(b);
}

void	ft_reverse_rotate_rra(t_stack **stack_a)
{
	t_stack	*temp_list;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	i = 0;
	temp_list = (*stack_a);
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = temp_list;
	while (i > 1)
	{
		temp_list = temp_list->next;
		i--;
	}
	temp_list->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_rotate_ra(t_stack **stack_a)
{
	t_stack	*temp_variable;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp_variable = (*stack_a);
	(*stack_a) = ft_lstlast(*stack_a);
	(*stack_a)->next = temp_variable;
	(*stack_a) = temp_variable->next;
	temp_variable->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_swap_sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	write(1, "sa\n", 3);
}

void	ft_push_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_stack;

	if (!(*stack_b))
		return ;
	temp_stack = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_a)->next = temp_stack;
	write(1, "pa\n", 3);
}
