/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:41:08 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 14:41:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_item **stack_from, t_item **stack_to, char push_to)
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
		*stack_to = (*stack_to)->prev;
		*stack_from = NULL;
	}
	else
	{
		(*stack_to)->prev = *stack_from;
		*stack_from = (*stack_from)->next;
		(*stack_to)->prev->next = *stack_to;
		*stack_to = (*stack_to)->prev;
	}
	set_index(stack_from, stack_to);
	ft_printf("p%c\n", push_to);
}
