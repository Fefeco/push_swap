/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:44:44 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 10:45:02 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_item **stack)
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
}
