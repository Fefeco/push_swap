/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 14:46:22 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_item **stack)
{
	int		stack_size;
	t_item	*smallest;

	stack_size = ft_stack_size(*stack);
	smallest = ft_get_node(*stack, "smallest");
	if (smallest->index <= stack_size / 2)
		while (smallest->index-- != 0)
			ra(stack);
	if (smallest->index > stack_size / 2)
		while (smallest->index++ != stack_size)
			rra(stack);
}
