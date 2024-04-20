/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/20 12:26:29 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_node_info(t_item **stack)
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
	ft_print_node_info(&a);
	ft_order(&a);
	ft_free_stack(&a);
	return (0);
}
