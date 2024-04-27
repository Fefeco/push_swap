/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 11:55:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_item **stack, char stk_id)
{
	t_item	*smallest;

	smallest = ft_get_node(*stack, SMALLEST);
	while (smallest->index != 0)
	{
		if (smallest->under_middle)
		{
			smallest->index--;
			rx(stack, stk_id);
		}
		else
		{
			smallest->index++;
			rrx(stack, stk_id);
		}
	}
	ft_printf("\n=====SORT STACK=====\n");
	ft_print_node_info(stack);
}
