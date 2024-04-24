/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/24 19:18:06 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_item **stack)
{
	int		stack_size;
	t_item	*smallest;

	stack_size = ft_stack_size(*stack);
	smallest = ft_get_node(*stack, SMALLEST);
	ft_printf("\n=====StACK=====\n");
	ft_print_node_info(stack);
	while (smallest->index != 0)
	{
		if (smallest->under_middle)
		{
			smallest->index--;
			ra(stack);
		}
		else
		{
			smallest->index++;
			rra(stack);
		}
	}
	ft_printf("\n=====StACK=====\n");
	ft_print_node_info(stack);
}
