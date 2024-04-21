/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 14:41:40 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*ft_get_node(t_item *stack, char *big_or_small)
{
	t_item	*node;

	node = stack;
	while (stack)
	{
		if (!ft_strncmp(big_or_small, "biggest", ft_strlen("biggest")))
			if ((*stack).value > node->value)
				node = stack;
		if (!ft_strncmp(big_or_small, "smallest", ft_strlen("smallest")))
			if ((*stack).value < node->value)
				node = stack;
		stack = (*stack).next;
	}
	return (node);
}

void	set_index(t_item **stack)
{
	int		i;
	t_item	*head;

	if (!*stack)
		return ;
	head = *stack;
	i = 0;
	while (*stack)
	{
		(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = head;
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

size_t	ft_stack_size(t_item *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		++len;
		stack = stack->next;
	}
	return (len);
}
