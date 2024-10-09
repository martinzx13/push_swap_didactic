/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algoritm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:55:12 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/23 15:19:05 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"


void	ft_sort_until_three_stack_b(t_stack **s_a, t_stack **s_b)
{
	int		opt_r;
	t_stack	*t_a;

	while (ft_lstsize(*s_a) > 3 && !ft_check_sorted_list(*s_a))
	{
		t_a = (*s_a);
		opt_r = ft_calculation_rotation_ab(*s_a, *s_b);
		while (opt_r >= 0)
		{
			if (opt_r == ft_stacks_rotation_ra_rb(*s_a, *s_b, t_a->number))
				opt_r = ft_apply_rotation_ra_rb(s_a, s_b, t_a->number, 'a');
			else if (opt_r == ft_reverse_stacks_rotation_rrr(*s_a,
					*s_b, t_a->number))
				opt_r = ft_apply_rotation_rra_rrb(s_a, s_b, t_a->number, 'a');
			else if (opt_r == ft_stacks_rotation_ra_rrb(*s_a,
					*s_b, t_a->number))
				opt_r = ft_apply_rotation_ra_rrb(s_a, s_b, t_a->number, 'a');
			else if (opt_r == ft_stacks_rotation_rra_rb(*s_a,
					*s_b, t_a->number))
				opt_r = ft_apply_rotation_rra_rb(s_a, s_b, t_a->number, 'a');
			else
				t_a = t_a->next;
		}
	}
}

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->number == ft_find_min(*stack_a))
	{
		ft_reverse_rotate_rra(stack_a);
		ft_swap_sa(stack_a);
	}
	else if ((*stack_a)->number == ft_find_max(*stack_a))
	{
		ft_rotate_ra(stack_a);
		if (!ft_check_sorted_list(*stack_a))
			ft_swap_sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_find_max(*stack_a)) == 1)
			ft_reverse_rotate_rra(stack_a);
		else
			ft_swap_sa(stack_a);
	}
}

t_stack	*ft_sort_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted_list(*stack_a))
		ft_push_pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted_list(*stack_a))
		ft_push_pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted_list(*stack_a))
		ft_sort_until_three_stack_b(stack_a, &stack_b);
	if (!ft_check_sorted_list(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

t_stack	**ft_sort_stack_a(t_stack **s_a, t_stack **s_b)
{
	int		opt_r;
	t_stack	*t_b;

	while (*s_b)
	{
		t_b = *s_b;
		opt_r = ft_calculation_rotation_ba(*s_a, *s_b);
		while (opt_r >= 0)
		{
			if (opt_r == ft_stacks_rotation_ra_rb_a(*s_a, *s_b, t_b->number))
				opt_r = ft_apply_rotation_ra_rb(s_a, s_b, t_b->number, 'b');
			else if (opt_r == ft_stacks_rotation_ra_rrb_a(*s_a, *s_b,
					t_b->number))
				opt_r = ft_apply_rotation_ra_rrb(s_a, s_b, t_b->number, 'b');
			else if (opt_r == ft_reverse_stacks_rotation_rrr_a(*s_a, *s_b,
					t_b->number))
				opt_r = ft_apply_rotation_rra_rrb(s_a, s_b, t_b->number, 'b');
			else if (opt_r == ft_stacks_rotation_rra_rb_a(*s_a, *s_b,
					t_b->number))
				opt_r = ft_apply_rotation_rra_rb(s_a, s_b, t_b->number, 'b');
			else
				t_b = t_b->next;
		}
	}
	return (s_a);
}

void	ft_push_swap_algoritm(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_swap_sa(stack_a);
	else
	{
		stack_b = ft_sort_stack_b(stack_a);
		stack_a = ft_sort_stack_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->number != ft_find_min(*stack_a))
				ft_rotate_ra(stack_a);
		}
		else
		{
			while ((*stack_a)->number != ft_find_min(*stack_a))
				ft_reverse_rotate_rra(stack_a);
		}
	}
}
