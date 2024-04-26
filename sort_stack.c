/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/26 14:57:01 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_item **stack)
{
	t_item	*smallest;

	smallest = ft_get_node(*stack, SMALLEST);
	while (smallest->index != 0)
	{
		if (smallest->under_middle)
		{
			smallest->index--;
			rx(stack, "ra");
		}
		else
		{
			smallest->index++;
			rrx(stack, "rrx");
		}
	}
	ft_printf("\n=====SORT STACK=====\n");
	ft_print_node_info(stack);
}
