/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 12:39:47 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_more_info(t_item **stack)	/// PRUEBA
{
	t_item	*head;

	head = *stack;
	while (*stack)
	{
		if (!(*stack)->prev)
			ft_printf("PREV NULL            || ");
		else
			ft_printf("PREV VAL %d - INDEX %d || ", (*stack)->prev->value,
				(*stack)->prev->index);
		ft_printf("NODE VAL %d - INDEX %d ||  ", (*stack)->value,
			(*stack)->index);
		if (!(*stack)->next)
			ft_printf("NEXT NULL\n");
		else
			ft_printf("NEXT VAL %d - INDEX %d\n", (*stack)->next->value,
				(*stack)->next->index);
		*stack = (*stack)->next;
	}
	*stack = head;
}

int	ft_print_node_info(t_item **stack)	/// PRUEBA
{
	t_item	*head;

	head = *stack;
	if (!*stack)
		return (1);
	while (*stack)
	{
		ft_printf("Index %d | Value %d\n", (*stack)->index, (*stack)->value);
		*stack = (*stack)->next;
	}
	*stack = head;
	return (0);
}

int	main(int argc, char **argv)
{
	t_item	*a;
	t_item	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1])
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_fill_stack(&a, argv, 1);
	}
	else
		ft_fill_stack(&a, ++argv, 0);
	if (!ft_is_ordered(&a))
		return (ft_free_stack(&a), 1);
	ft_print_node_info(&a);	/// PRUEBA
	ft_order(&a);
	ft_print_node_info(&a);	/// PRUEBA
	set_index(&a);	/// PRUEBA
	ft_print_more_info(&a);	/// PRUEBA
	ft_free_stack(&a);
	return (0);
}
