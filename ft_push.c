/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:00:07 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/21 09:26:00 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rotation_ra_rb(t_stack **stack_a, t_stack **stack_b,
	int num_to_push, char list)
{
	if (list == 'a')
	{
		while ((*stack_a)->number != num_to_push
			&& ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_rotate_rr(stack_a, stack_b);
		while ((*stack_a)->number != num_to_push)
			ft_rotate_ra(stack_a);
		while (ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_rotate_rb(stack_b);
		ft_push_pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->number != num_to_push
			&& ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_rotate_rr(stack_a, stack_b);
		while ((*stack_b)->number != num_to_push)
			ft_rotate_rb(stack_b);
		while (ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_rotate_ra(stack_a);
		ft_push_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rotation_rra_rrb(t_stack **stack_a, t_stack **stack_b,
	int num_to_push, char list)
{
	if (list == 'a')
	{
		while ((*stack_a)->number != num_to_push
			&& ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_reverse_rotate_rrr(stack_a, stack_b);
		while ((*stack_a)->number != num_to_push)
			ft_reverse_rotate_rra(stack_a);
		while (ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_reverse_rotate_rrb(stack_b);
		ft_push_pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->number != num_to_push
			&& ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_reverse_rotate_rrr(stack_a, stack_b);
		while ((*stack_b)->number != num_to_push)
			ft_reverse_rotate_rrb(stack_b);
		while (ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_reverse_rotate_rra(stack_a);
		ft_push_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rotation_ra_rrb(t_stack **stack_a, t_stack **stack_b,
	int num_to_push, char list)
{
	if (list == 'a')
	{
		while ((*stack_a)->number != num_to_push)
			ft_rotate_ra(stack_a);
		while (ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_reverse_rotate_rrb(stack_b);
		ft_push_pb(stack_a, stack_b);
	}
	else
	{
		while (ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_rotate_ra(stack_a);
		while ((*stack_b)->number != num_to_push)
			ft_reverse_rotate_rrb(stack_b);
		ft_push_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rotation_rra_rb(t_stack **stack_a, t_stack **stack_b,
	int num_to_push, char list)
{
	if (list == 'a')
	{
		while ((*stack_a)->number != num_to_push)
			ft_reverse_rotate_rra(stack_a);
		while (ft_check_place_b(*stack_b, num_to_push) > 0)
			ft_rotate_rb(stack_b);
		ft_push_pb(stack_a, stack_b);
	}
	else
	{
		while (ft_check_place_a(*stack_a, num_to_push) > 0)
			ft_reverse_rotate_rra(stack_a);
		while ((*stack_b)->number != num_to_push)
			ft_rotate_rb(stack_b);
		ft_push_pa(stack_a, stack_b);
	}
	return (-1);
}
