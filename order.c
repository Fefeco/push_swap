/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 14:25:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_three(t_item **stack)
{
	t_item	*biggest;

	biggest = ft_get_node(*stack, "biggest");
	if (*stack == biggest)
		ra(stack);
	if ((*stack)->next == biggest)
		rra(stack);
	ft_print_more_info(stack);	/// PRUEBA
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
/*	set_index(stack);*/
}

void	ft_order(t_item **stack_a, t_item **stack_b)
{
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	if (stack_size <= 3)
		return ft_order_three(stack_a);
/*	while (stack_size > 3)
	{
		ft_push_item(stack_a, stack_b);
		--stack_size;
	}
	ft_order_three(stack_a);*/
	stack_size = ft_stack_size(*stack_b);
/*	while (stack_size)
	{
		ft_push_item(stack_b, stack_a);
		--stack_size;
	}
*/	ft_sort_stack(stack_a);
}
