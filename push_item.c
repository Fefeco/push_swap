/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/23 14:04:03 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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
			else
				if (min_dist > dist)
				{
					min_dist = dist;
					item->target = stack;
				}
		}
		stack = stack->next;
	}
	if (!min_dist)
		item->target = ft_get_node(stack, "smallest");
	ft_printf("Target en INDEX %d\n", item->target->index);	/// PRUEBA
}

int	ft_no_name(t_item *item, int len_stack_a, int len_stack_b)
{
	if (item->index > item->len_to_end)
		item->under_middle = false;
	else
		item->under_middle = true;
	if (item->under_limit && item->target->under_limit)
		if (item->index >= item->target->index)
			return (item->index);
		else
			return (item->target->index);
	else if (item->index > limit_a && item->target->index > limit_b)
		if (len_stack_a - item->index >= len_stack_b - item->target->index)
			return (len_stack_a - item->index);
		else
			return (len_stack_b - item->target->index);
	else
}

void	ft_calc_cost(t_item *item, t_item **stack_to, int push_to)
{
	if (push_to == PUSH_TO_A)
		ft_find_target_on_b(item, *stack_to);
	if (push_to == PUSH_TO_B)
		ft_find_target_on_a(item, *stack_to);
	ft_no_name(item);
}

void	ft_push_item(t_item **stack_a, t_item **stack_b, int push_to)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = ft_stack_size(*stack_a);
	len_stack_b = ft_stack_size(*stack_b);
	if (!len_stack_b && push_to == PUSH_TO_A)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		return ;
	}
	while ((*stack_a)->next)
	{
		(*stack_a)->len_to_end = len_stack_a - (*stack_a)->index;
		ft_calc_cost(*stack_a, stack_b, push_to);
		*stack_a = (*stack_a)->next;
	}
	cheapest = ft_get_node(*stack_from, "cheapest");
}
