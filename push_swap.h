/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:07:21 by juan-pma          #+#    #+#             */
/*   Updated: 2023/08/24 10:24:14 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	ft_print_list(t_stack *stack, char list);

//############## Call function utilities.
int		ft_apply_rotation_ra_rb(t_stack **stack_a, t_stack **stack_b,
			int number_push, char bool);
int		ft_apply_rotation_rra_rrb(t_stack **stack_a, t_stack **stack_b,
			int num_to_push, char list);
int		ft_apply_rotation_ra_rrb(t_stack **stack_a, t_stack **stack_b,
			int num_to_push, char list);
int		ft_apply_rotation_rra_rb(t_stack **stack_a, t_stack **stack_b,
			int num_to_push, char list);

//############## Other utilities. 
int		ft_find_max(t_stack *stack_a);
int		ft_find_min(t_stack *stack_a);
void	ft_free(t_stack **lst);
int		ft_check_place_b(t_stack *stack_b, int number_to_push);
int		ft_check_place_a(t_stack *stack_a, int number_to_push);

//############## Error Managment.
void	ft_error_display(void);
int		ft_check_dup(t_stack *list_a);
int		ft_check_sorted_list(t_stack *stack_a);

//############## Libft Managment.
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isnumeric(char *str);
int		ft_lstsize(t_stack *list_a);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_find_index(t_stack *stack, int num_max);
void	ft_free_string(char **string);

//############## Main Function.
int		main(int argc, char **argv);

//############## Creating the Linked List 
t_stack	*ft_create_list(int num_of_args, char **argv);
t_stack	*ft_start_linked_lst(char **argv);
void	ft_error_display(void);
char	**ft_split(char const *s, char c);

//############# Operations management.
void	ft_swap_sa(t_stack **stack_a);
void	ft_push_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_push_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sub_rrb(t_stack **b);
void	ft_reverse_rotate_rra(t_stack **stack_a);
void	ft_reverse_rotate_rrb(t_stack **stack_b);
void	ft_rotate_ra(t_stack **stack_a);
void	ft_rotate_rb(t_stack **stack_b);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);

//############# Sorting Algoritm 
void	ft_push_swap_algoritm(t_stack **list_a);

// Sorting algoritm rotate calculations. 
int		ft_calculation_rotation_ab(t_stack *stack_a,
			t_stack *stack_b);
int		ft_calculation_rotation_ba(t_stack *stack_a, t_stack *stack_b);

// Rotations stack_a -----> stack_b 
int		ft_reverse_stacks_rotation_rrr(t_stack *stack_a,
			t_stack *stack_b, int number_to_push);
int		ft_stacks_rotation_rra_rb(t_stack *stack_a,
			t_stack *stack_b, int num_to_push);
int		ft_stacks_rotation_ra_rrb(t_stack *stack_a,
			t_stack *stack_b, int num_to_push);
int		ft_stacks_rotation_ra_rb(t_stack *stack_a,
			t_stack *stack_b, int num_to_push);

// Rotations stack_b -----> stack_a
int		ft_reverse_stacks_rotation_rrr_a(t_stack *stack_a,
			t_stack *stack_b, int number_to_push);
int		ft_stacks_rotation_rra_rb_a(t_stack *stack_a, t_stack *stack_b,
			int num_to_push);
int		ft_stacks_rotation_ra_rb_a(t_stack *stack_a, t_stack *stack_b,
			int num_to_push);
int		ft_stacks_rotation_ra_rrb_a(t_stack *stack_a, t_stack *stack_b,
			int num_to_push);

#endif
