/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 13:02:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_on_b(t_item *item, t_item *stack_to)
{
	int		dist;
	int		min_dist;
	t_item	*head;

	head = stack_to;
	min_dist = 0;
	while (stack_to && min_dist != 1)
	{
		if (item->value > stack_to->value)
		{
			dist = item->value - stack_to->value;
			if (dist < min_dist || !min_dist)
			{
				min_dist = dist;
				item->target = stack_to;
			}
		}
		stack_to = stack_to->next;
	}
	if (!min_dist)
		item->target = ft_get_node(head, BIGGEST);
}

void	ft_find_target_on_a(t_item *item, t_item *stack_to)
{
	int		dist;
	int		min_dist;
	t_item	*head;

	head = stack_to;
	min_dist = 0;
	while (stack_to && min_dist != 1)
	{
		if (item->value < stack_to->value)
		{
			dist = stack_to->value - item->value;
			if (dist < min_dist || !min_dist)
			{
				min_dist = dist;
				item->target = stack_to;
			}
		}
		stack_to = stack_to->next;
	}
	if (!min_dist)
		item->target = ft_get_node(head, SMALLEST);
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

void	ft_calc_cost(t_item *item, t_item **stack_to, char push_to)
{
	t_item	*head;

	head = item;
	while (item)
	{
		if (push_to == PUSH_TO_B)
			ft_find_target_on_b(item, *stack_to);
		else if (push_to == PUSH_TO_A)
		{
			ft_printf("STACK B -> ");
			ft_find_target_on_a(item, *stack_to);
		ft_printf("ITEM %d COST %d -> TGT %d INDEX= %d\n", item->value, item->cost, item->target->value, item->target->index);
		}
		item = item->next;
	}
	item = head;
	while (item)
	{
		item->cost = ft_calc_moves(item);
		item = item->next;
	}
}

void	ft_prep_to_push(t_item **stack_from, t_item **stack_to, char push_to)
{
	t_item	*cheapest;
	int		push_from;

	push_from = 'a';
	if (push_from == push_to)
		push_from = 'b';
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
			rx(stack_from, push_from);
		else
			rrx(stack_from, push_from);
		set_index(stack_from, NULL);
	}
	while (cheapest->target->index != 0)
	{
		if (cheapest->target->under_middle)
			rx(stack_to, push_to);
		else
			rrx(stack_to, push_to);
		set_index(stack_to, NULL);
	}
}

void	ft_push_item(t_item **stack_from, t_item **stack_to, char push_to)
{
	int	len_stk_from;
	int	len_stk_to;

	len_stk_from = ft_stack_size(*stack_from);
	len_stk_to = ft_stack_size(*stack_to);
	if (len_stk_to < 2 && push_to == PUSH_TO_B)
		return (push(stack_from, stack_to, push_to));
	ft_set_mid(*stack_from, *stack_to, len_stk_from, len_stk_to);
	ft_calc_cost(*stack_from, stack_to, push_to);
	ft_prep_to_push(stack_from, stack_to, push_to);
	push(stack_from, stack_to, push_to);
}
