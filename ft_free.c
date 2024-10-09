/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:14:34 by juan-pma          #+#    #+#             */
/*   Updated: 2023/10/23 09:14:57 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function frees the stack.
void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->number = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_free_string(char **string)
{
	char	*value;

	if (!string)
		return ;
	while (*string)
	{
		value = *string;
		free(value);
		string++;
	}
	*string = NULL;
}
