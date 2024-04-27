/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:57:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 14:46:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_mid(t_item *stk_from, t_item *stk_to, int len_from, int len_to)
{
	while (stk_from)
	{
		stk_from->len_to_end = len_from - stk_from->index;
		stk_from = stk_from->next;
	}
	while (stk_to)
	{
		stk_to->len_to_end = len_to - stk_to->index;
		stk_to = stk_to->next;
	}
}

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
