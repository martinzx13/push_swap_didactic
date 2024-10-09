/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:07:43 by juan-pma          #+#    #+#             */
/*   Updated: 2023/09/19 10:17:31 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/push_swap.h"


t_stack	*ft_new_node(int j)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = j;
	new_node->next = NULL;
	return (new_node);
}

void	ft_next_node(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(ft_lstlast(*stack))->next = new_node;
}

t_stack	*ft_start_linked_lst(char **argv)
{
	t_stack	*stack_a;
	char	**temp_num_holder;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	temp_num_holder = ft_split(argv[1], ' ');
	while (temp_num_holder[i])
	{
		if (!ft_isnumeric(temp_num_holder[i]))
		{
			ft_free_string(temp_num_holder);
			ft_free(&stack_a);
			free(temp_num_holder);
			ft_error_display();
		}
		j = ft_atoi(temp_num_holder[i]);
		ft_next_node(&stack_a, ft_new_node(j));
		i++;
	}
	ft_free_string(temp_num_holder);
	free(temp_num_holder);
	return (stack_a);
}

t_stack	*ft_create_list(int num_of_args, char **argv)
{
	t_stack	*list_a;
	int		i;
	int		j;

	i = 1;
	list_a = NULL;
	if (num_of_args == 1 || (num_of_args == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	if (num_of_args == 2)
		list_a = ft_start_linked_lst(argv);
	else
	{
		while (i < num_of_args)
		{
			if (!ft_isnumeric(argv[i]))
			{
				ft_free(&list_a);
				ft_error_display();
			}
			j = ft_atoi(argv[i]);
			ft_next_node(&list_a, ft_new_node(j));
			i++;
		}
	}
	return (list_a);
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;

	list_a = ft_create_list(argc, argv);
	if (list_a && ft_check_dup(list_a))
	{
		ft_free(&list_a);
		ft_error_display();
	}
	if (list_a && !ft_check_sorted_list(list_a))
		ft_push_swap_algoritm(&list_a);
	ft_free(&list_a);
	return (0);
}
