/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:44:44 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/24 17:55:13 by fcarranz         ###   ########.fr       */
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
	ft_printf("ra\n");	/// PRUEBA
}

void	rra(t_item **stack)
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
	ft_printf("rra\n");	/// PRUEBA
}

void	sa(t_item **stack)
{
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next = *stack;
	(*stack)->prev->prev = NULL;
	(*stack)->next->prev = *stack;
	*stack = (*stack)->prev;
	ft_printf("sa\n");	/// PRUEBA
}

void	push(t_item **stack_from, t_item **stack_to)
{
	if (!*stack_to)
	{
		//ft_printf("ACA\n");				/// PRUEBA
		//ft_print_node_info(stack_from);	/// PRUEBA
		*stack_to = *stack_from;
		*stack_from = (*stack_from)->next;
		(*stack_from)->prev = NULL;
		(*stack_to)->next = NULL;
		return ;
	}
	//ft_printf("Ahora ACA\n");			/// PRUEBA
	//ft_print_node_info(stack_from);		/// PRUEBA
	(*stack_to)->prev = *stack_from;
	*stack_from = (*stack_from)->next;
	(*stack_to)->prev->next = *stack_to;
	*stack_to = (*stack_to)->prev;
	(*stack_from)->prev = NULL;
}
