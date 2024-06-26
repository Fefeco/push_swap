/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/01 13:40:51 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_order_three(t_item **stack)
{
	t_item	*biggest_node;

	biggest_node = ft_get_node(*stack, BIGGEST);
	if (*stack == biggest_node)
		rx(stack, 'a');
	if ((*stack)->next == biggest_node)
		rrx(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		sx(stack, 'a');
	set_index(stack, NULL);
}

void	ft_order(t_item **stack_a, t_item **stack_b)
{
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	if (stack_size == 2)
		return (sx(stack_a, 'a'));
	if (stack_size == 3)
		return (ft_order_three(stack_a));
	while (stack_size-- > 3)
		ft_push_item(stack_a, stack_b, PUSH_TO_B);
	ft_order_three(stack_a);
	stack_size = ft_stack_size(*stack_b);
	while (stack_size)
	{
		ft_push_item(stack_b, stack_a, PUSH_TO_A);
		--stack_size;
	}
	ft_sort_stack(stack_a, 'a');
}
