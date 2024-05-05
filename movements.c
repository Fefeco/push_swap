/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:44:44 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/05 14:34:39 by fcarranz         ###   ########.fr       */
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
	if ((*stack)->next->next)
		(*stack)->next->next->prev = (*stack)->next->prev;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next = *stack;
	*stack = (*stack)->prev;
	if (s_to)
		ft_printf("s%c\n", s_to);
}
