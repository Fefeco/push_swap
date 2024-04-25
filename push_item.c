/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/25 18:19:31 by fcarranz         ###   ########.fr       */
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

void	ft_prep_to_push(t_item **stack_from, t_item **stack_to)
{
	t_item	*cheapest;

	cheapest = ft_get_node(*stack_from, CHEAPEST);
	while (cheapest->index != 0 && cheapest->target->index != 0)
	{
		if (cheapest->under_middle && cheapest->target->under_middle)
			rr(stack_from, stack_to);
		else if (!cheapest->under_middle && !cheapest->target->under_middle)
			rrr(stack_from, stack_to);
		else
			break ;
		set_index(stack_from, stack_to);
	}
	while (cheapest->index != 0)
	{
		if (cheapest->under_middle)
			rx(stack_from, "a");
		else
			rrx(stack_from, "a");
		set_index(stack_from, NULL);
	}
	while (cheapest->target->index != 0)
	{
		if (cheapest->target->under_middle)
			rx(stack_to, "b");
		else
			rrx(stack_to, "b");
		set_index(stack_to, NULL);
	}
}

void	ft_push_item(t_item **stack_a, t_item **stack_b, int push_to)
{
	int		len_stack_a;
	int		len_stack_b;
	t_item	*stack;

	stack = *stack_a;
	if (push_to == PUSH_TO_A)
		stack = *stack_b;
	len_stack_a = ft_stack_size(*stack_a);
	len_stack_b = ft_stack_size(*stack_b);
	if (len_stack_b < 2 && push_to == PUSH_TO_B)
		return (push(stack_a, stack_b));
	while (stack)
	{
		if (push_to == PUSH_TO_B)
			stack->len_to_end = len_stack_a - stack->index;
		else
			stack->len_to_end = len_stack_b - stack->index;
		ft_calc_cost(stack, stack_b, push_to);
		stack = stack->next;
	}
	if (push_to == PUSH_TO_A)
	{
		ft_prep_to_push(stack_b, stack_a);
		push(stack_b, stack_a);
	}
	else
	{
		ft_prep_to_push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
}
