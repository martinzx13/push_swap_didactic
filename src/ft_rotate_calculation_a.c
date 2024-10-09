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

#include "../library/push_swap.h"


// This function calculates how many times we should rotate the stacks together.
int	ft_reverse_stacks_rotation_rrr(t_stack *stack_a,
	t_stack *stack_b, int number_to_push)
{
	int	rotation;

	rotation = 0;
	if (ft_check_place_b(stack_b, number_to_push))
		rotation = ft_lstsize(stack_b)
			- ft_check_place_b(stack_b, number_to_push);
	if ((rotation < (ft_lstsize(stack_a)
				- ft_find_index(stack_a, number_to_push)))
		&& ft_find_index(stack_a, number_to_push))
	{
		rotation = ft_lstsize(stack_a)
			- ft_find_index(stack_a, number_to_push);
	}
	return (rotation);
}

int	ft_stacks_rotation_rra_rb(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = 0;
	if (ft_find_index(stack_a, num_to_push))
		num_rot = ft_lstsize(stack_a)
			- ft_find_index(stack_a, num_to_push);
	num_rot = ft_check_place_b(stack_b, num_to_push) + num_rot;
	return (num_rot);
}

int	ft_stacks_rotation_ra_rrb(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = 0;
	if (ft_check_place_b(stack_b, num_to_push))
		num_rot = ft_lstsize(stack_b)
			- ft_check_place_b(stack_b, num_to_push);
	num_rot = ft_find_index(stack_a, num_to_push) + num_rot;
	return (num_rot);
}

int	ft_stacks_rotation_ra_rb(t_stack *stack_a,
	t_stack *stack_b, int num_to_push)
{
	int	num_rot;

	num_rot = ft_check_place_b(stack_b, num_to_push);
	if (num_rot < ft_find_index(stack_a, num_to_push))
		num_rot = ft_find_index(stack_a, num_to_push);
	return (num_rot);
}

int	ft_calculation_rotation_ab(t_stack *s_a, t_stack *s_b)
{
	int		num_rot;
	t_stack	*tmp_s;

	tmp_s = s_a;
	num_rot = ft_reverse_stacks_rotation_rrr(s_a,
			s_b, s_a->number);
	while (tmp_s)
	{
		if (num_rot
			> ft_stacks_rotation_ra_rb(s_a, s_b, tmp_s->number))
			num_rot = ft_stacks_rotation_ra_rb(s_a, s_b, tmp_s->number);
		if (num_rot
			> ft_reverse_stacks_rotation_rrr(s_a,
				s_b, tmp_s->number))
			num_rot = ft_reverse_stacks_rotation_rrr(s_a, s_b, tmp_s->number);
		if (num_rot
			> ft_stacks_rotation_ra_rrb(s_a, s_b, tmp_s->number))
			num_rot = ft_stacks_rotation_ra_rrb(s_a, s_b, tmp_s->number);
		if (num_rot
			> ft_stacks_rotation_rra_rb(s_a, s_b, tmp_s->number))
			num_rot = ft_stacks_rotation_rra_rb(s_a, s_b, tmp_s->number);
		tmp_s = tmp_s->next;
	}
	return (num_rot);
}
