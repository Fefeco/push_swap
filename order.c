/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 10:50:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*ft_get_biggest(t_item *stack)
{
	t_item	*biggest_node;

	biggest_node = stack;
	while (stack)
	{
		if ((*stack).value > biggest_node->value)
			biggest_node = stack;
		stack = (*stack).next;
	}
	return (biggest_node);
}

void	ft_order_three(t_item **stack)
{
	t_item	*biggest;

	biggest = ft_get_biggest(*stack);
	if (*stack == biggest)
		ra(stack);
/*	if (*stack->next == biggest)
		rra(stack);
	if (*stack->value > *stack->next->value)
		sa(stack);*/
	set_index(stack);
}

void	ft_order(t_item **stack)
{
	if (ft_stack_size(*stack) <= 3)
		ft_order_three(stack);
}
