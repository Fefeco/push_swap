/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:57:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/28 11:51:29 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_mid(t_item *stk_from, t_item *stk_to, int len_from, int len_to)
{
	t_item	*tmp;
	int		len;
	int		i;

	tmp = stk_from;
	len = len_from;
	i = 0;
	while (i < 2)
	{
		++i;
		while (tmp)
		{
			tmp->len_to_end = len - tmp->index;
			tmp->under_middle = tmp->index < tmp->len_to_end;
			tmp = tmp->next;
		}
		tmp = stk_to;
		len = len_to;
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
