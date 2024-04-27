/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *stack_idements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:44:44 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 11:53:43 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_item **stack_a, t_item **stack_b)
{
	rx(stack_a, 0);
	rx(stack_b, 0);
	ft_printf("rr\n");
}

void	rrr(t_item **stack_a, t_item **stack_b)
{
	rrx(stack_a, 0);
	rrx(stack_b, 0);
	ft_printf("rrr\n");
}

void	rx(t_item **stack, char r_to)
{
	t_item	*last_item;

	last_item = *stack;
	while (last_item->next)
		last_item = last_item->next;
	last_item->next = *stack;
	(*stack)->prev = last_item;
	last_item = last_item->next;
	*stack = (*stack)->next;
	last_item->next = NULL;
	(*stack)->prev = NULL;
	if (r_to)
		ft_printf("r%c\n", r_to);
}

void	rrx(t_item **stack, char rr_to)
{
	t_item	*last_item;

	last_item = *stack;
	while (last_item->next)
		last_item = last_item->next;
	last_item->prev->next = NULL;
	last_item->prev = NULL;
	last_item->next = *stack;
	(*stack)->prev = last_item;
	*stack = last_item;
	if (rr_to)
		ft_printf("rr%c\n", rr_to);
}

void	sx(t_item **stack, char s_to)
{
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next = *stack;
	(*stack)->prev->prev = NULL;
	(*stack)->next->prev = *stack;
	*stack = (*stack)->prev;
	if (s_to)
		ft_printf("s%c\n", s_to);
}

void	push(t_item **stack_from, t_item **stack_to)
{
	if (!*stack_to)
	{
		*stack_to = *stack_from;
		*stack_from = (*stack_from)->next;
		(*stack_from)->prev = NULL;
		(*stack_to)->next = NULL;
	}
	else if (!(*stack_from)->next)
	{
		(*stack_to)->prev = *stack_from;
		(*stack_from)->next = *stack_to;
		stack_to = stack_from;
		*stack_from = NULL;
	}
	else
	{
		(*stack_to)->prev = *stack_from;
		*stack_from = (*stack_from)->next;
		(*stack_to)->prev->next = *stack_to;
		*stack_to = (*stack_to)->prev;
		(*stack_from)->prev = NULL;
	}
	set_index(stack_from, stack_to);
}
