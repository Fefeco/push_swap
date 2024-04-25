/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/25 11:01:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_on_b(t_item *item, t_item *stack)
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
			else if (min_dist > dist)
			{
				min_dist = dist;
				item->target = stack;
			}
		}
		stack = stack->next;
	}
	if (!min_dist)
		item->target = ft_get_node(stack, SMALLEST);
//	ft_printf("Target en INDEX %d\n", item->target->index);	/// PRUEBA
}

int	ft_calc_moves(t_item *item)
{
	item->under_middle = item->index < item->len_to_end;
	if (item->under_middle && item->target->under_middle)
	{
		if (item->index >= item->target->index)
			return (item->index);
		else
			return (item->target->index);
	}
	else if (!item->under_middle && !item->target->under_middle)
	{
		if (item->len_to_end >= item->target->len_to_end)
			return (item->len_to_end);
		else
			return (item->target->len_to_end);
	}
	else
	{
		if (item->under_middle)
			return (item->index + item->target->len_to_end);
		else
			return (item->len_to_end + item->target->index);
	}
}

void	ft_calc_cost(t_item *item, t_item **stack_to, int push_to)
{
	if (push_to == PUSH_TO_B)
		ft_find_target_on_b(item, *stack_to);
	/*if (push_to == PUSH_TO_A)
		ft_find_target_on_a(item, *stack_to);*/
	item->cost = ft_calc_moves(item);
}

void	ft_push_item(t_item **stack_a, t_item **stack_b, int push_to)
{
	int		len_stack_a;
	int		len_stack_b;
	t_item	*cheapest;

	len_stack_a = ft_stack_size(*stack_a);
	len_stack_b = ft_stack_size(*stack_b);
/*	ft_printf("\n===== STACK_A =====\n");	/// PRUEBA
	ft_print_more_info(stack_a);	/// PRUEBA
	ft_printf("\n===== STACK_B =====\n");	/// PRUEBA
	ft_print_more_info(stack_b);	/// PRUEBA*/
	if (len_stack_b < 2 && push_to == PUSH_TO_B)
		return (push(stack_a, stack_b));
	while ((*stack_a)->next)
	{
		(*stack_a)->len_to_end = len_stack_a - (*stack_a)->index;
		ft_calc_cost(*stack_a, stack_b, push_to);
		*stack_a = (*stack_a)->next;
		set_index(stack_a, stack_b);
	}
	while ((*stack_a)->prev)
		*stack_a = (*stack_a)->prev;
	if (push_to == PUSH_TO_B)
		cheapest = ft_get_node(*stack_a, CHEAPEST);
	if (push_to == PUSH_TO_A)
		push(stack_b, stack_a);
	else
		push(stack_a, stack_b);
}
