/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 16:57:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_item **stack)
{
	t_item	*next_item;

	if (!stack)
		return ;
	while (*stack)
	{
		next_item = (*stack)->next;
		free (*stack);
		*stack = next_item;
	}
	stack = NULL;
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (*array)
		while (array[i])
			free (array[i++]);
	free (array);
	array = NULL;
}

int	ft_is_ordered(t_item **stack)
{
	long	prev;
	t_item	*item;

	item = *stack;
	prev = (long)INT_MIN - 1;
	while (item)
	{
		if (prev > (long)item->value)
			return (1);
		prev = item->value;
		item = item->next;
	}
	return (0);
}
