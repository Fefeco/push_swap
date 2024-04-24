/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/24 18:18:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*ft_get_node(t_item *stack, char target)
{
	t_item	*node;

	node = stack;
	while (stack)
	{
		if (target == BIGGEST)
		{
			if ((*stack).value > node->value)
				node = stack;
		}
		else if (target == SMALLEST)
		{
			if ((*stack).value < node->value)
				node = stack;
		}
		else if (target == CHEAPEST)
			if ((*stack).cost < node->cost)
				node = stack;
		stack = (*stack).next;
	}
	return (node);
}

void	set_index(t_item **stack_a, t_item **stack_b)
{
	int		i;
	int		j;
	t_item	*tmp;

	tmp = *stack_a;
	j = 0;
	while (j < 2)
	{
		++j;
		i = 0;
		while (tmp)
		{
			tmp->index = i++;
			ft_printf("N VAL %d index %d\n", tmp->value, tmp->index);
			tmp = tmp->next;
		}
		tmp = *stack_b;
	}
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
