/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/25 20:20:18 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_more_info(t_item **stack)	/// PRUEBA
{
	t_item	*item;

	item = *stack;
	if (!item)
		return (ft_printf("(null)\n"), 1);
	while (item)
	{
		if (!item->prev)
			ft_printf("PREV NULL         || ");
		else
			ft_printf("PREV VAL %d - I %d || ", item->prev->value,
				item->prev->index);
		ft_printf("N VAL %d - I %d", item->value, item->index);
		if (item->target)
			ft_printf(" T %d ||  ", item->target->index);
		else
			ft_printf(" ||  ");
		if (!item->next)
			ft_printf("NEXT NULL\n");
		else
			ft_printf("NEXT VAL %d - I %d\n", item->next->value,
				item->next->index);
		item = item->next;
	}
	return (0);
}

int	ft_print_node_info(t_item **stack)	/// PRUEBA
{
	t_item	*item;

	item = *stack;
	if (!item)
		return (ft_printf("(null)\n"), 1);
	while (item)
	{
		ft_printf("Index %d | Value %d\n", item->index, item->value);
		item = item->next;
	}
	return (0);
}

void	ft_free_stack(t_item **stack)
{
	t_item	*next_item;

	if (!stack)
		return ;
	while (*stack)
	{
		next_item = (*stack)->next;
		free (*stack);
		*stack = next_item;
	}
	stack = NULL;
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
	if (!ft_is_ordered(&a) || ft_stack_size(a) == 1)
		return (ft_free_stack(&a), 1);
	ft_printf("\n===== STACK A =====\n");	/// PRUEBA
	ft_print_node_info(&a);					/// PRUEBA
	ft_printf("\n===== STACK B =====\n");	/// PRUEBA
	ft_print_node_info(&b);					/// PRUEBA
	ft_order(&a, &b);
//	ft_print_node_info(&a);					/// PRUEBA
//	set_index(&a);							/// PRUEBA
//	ft_print_more_info(&a);					/// PRUEBA
	ft_printf("\n===== FIN STACK A =====\n");	/// PRUEBA
	ft_print_node_info(&a);					/// PRUEBA
	ft_printf("\n===== FIN STACK B =====\n");	/// PRUEBA
	ft_print_node_info(&b);					/// PRUEBA
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
