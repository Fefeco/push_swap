/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/22 11:10:10 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ft_find_target(t_item *item, t_item *stack)
{
	int		dist;
	int		min_dist;

	min_dist = 0;
	while (stack->next && min_dist != 1)
	{
		if (item->value < stack->value)
		{
			dist = stack->value - item->value;
			if (!min_dist)
			{
				min_dist = dist;
				item->target = stack;
			}
			else
				if (min_dist > dist)
				{
					min_dist = dist;
					item->target = stack;
				}
		}
		stack = stack->next;
	}
	ft_printf("Target en INDEX %d\n", item->target->index);
}

void	ft_calc_cost(t_item *item, t_item **stack_to)
{
	t_item	*head;

	head = *stack_to;
	ft_find_target(item, *stack_to);
	*stack_to = (*stack_to)->next;
}

void	ft_push_item(t_item **stack_from, t_item **stack_to)
{
	t_item	*cheapest;

	if (!*stack_to)
	{
		push(stack_from, stack_to);
		push(stack_from, stack_to);
	}
	while (*stack_from->next)
	{
		ft_calc_cost(*stack_from, stack_to);
	}
	cheapest = ft_get_node(*stack_from);
}
