/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/27 14:26:18 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_item **stack, char stk_id)
{
	t_item	*smallest;

	smallest = ft_get_node(*stack, SMALLEST);
	smallest->len_to_end = ft_stack_size(*stack) - smallest->index;
	smallest->under_middle = smallest->index < smallest->len_to_end;
	while (smallest->index != 0 && smallest->len_to_end != 0)
	{
		if (smallest->under_middle)
		{
			smallest->index--;
			rx(stack, stk_id);
		}
		else
		{
			smallest->len_to_end--;
			rrx(stack, stk_id);
		}
	}
	set_index(stack, NULL);
}
