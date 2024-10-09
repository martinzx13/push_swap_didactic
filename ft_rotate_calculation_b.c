/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:40:47 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/23 14:52:30 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates how many times we should rotate the stacks together.
int	ft_reverse_stacks_rotation_rrr_a(t_stack *stack_a,
	t_stack *stack_b, int number_to_push)
{
	int	rotation;

	rotation = 0;
	if (ft_check_place_a(stack_a, number_to_push))
	{
		rotation = ft_lstsize(stack_a)
			- ft_check_place_a(stack_a, number_to_push);
	}
	if ((rotation < (ft_lstsize(stack_b)
				- ft_find_index(stack_b, number_to_push)))
		&& ft_find_index(stack_b, number_to_push))
	{
		rotation = ft_lstsize(stack_b)
			- ft_find_index(stack_b, number_to_push);
	}
	return (rotation);
}

int	ft_stacks_rotation_rra_rb_a(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = 0;
	if (ft_check_place_a(stack_a, num_to_push))
		num_rot = ft_lstsize(stack_a) - ft_check_place_a(stack_a, num_to_push);
	num_rot += ft_find_index(stack_b, num_to_push);
	return (num_rot);
}

int	ft_stacks_rotation_ra_rrb_a(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = 0;
	if (ft_find_index(stack_b, num_to_push))
		num_rot = ft_lstsize(stack_b)
			- ft_find_index(stack_b, num_to_push);
	num_rot = ft_check_place_a(stack_a, num_to_push) + num_rot;
	return (num_rot);
}

int	ft_stacks_rotation_ra_rb_a(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = ft_check_place_a(stack_a, num_to_push);
	if (num_rot < ft_find_index(stack_b, num_to_push))
		num_rot = ft_find_index(stack_b, num_to_push);
	return (num_rot);
}

int	ft_calculation_rotation_ba(t_stack *s_a, t_stack *s_b)
{
	int		num_r;
	t_stack	*tmp_s;

	tmp_s = s_b;
	num_r = ft_reverse_stacks_rotation_rrr_a(s_a,
			s_b, s_b->number);
	while (tmp_s)
	{
		if (num_r > ft_stacks_rotation_ra_rb_a(s_a, s_b, tmp_s->number))
			num_r = ft_stacks_rotation_ra_rb_a(s_a, s_b, tmp_s->number);
		if (num_r > ft_reverse_stacks_rotation_rrr_a (s_a,
				s_b, tmp_s->number))
			num_r = ft_reverse_stacks_rotation_rrr_a (s_a, s_b, tmp_s->number);
		if (num_r > ft_stacks_rotation_ra_rrb_a(s_a, s_b, tmp_s->number))
			num_r = ft_stacks_rotation_ra_rrb_a(s_a, s_b, tmp_s->number);
		if (num_r > ft_stacks_rotation_rra_rb_a(s_a, s_b, tmp_s->number))
			num_r = ft_stacks_rotation_rra_rb_a(s_a, s_b, tmp_s->number);
		tmp_s = tmp_s->next;
	}
	return (num_r);
}
