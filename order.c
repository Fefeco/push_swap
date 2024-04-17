/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 19:18:32 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_three(t_item **stack)
{
	t_item	biggest;

	biggest = ft_get_biggest(stack);
	if (*stack == biggest)
		ra(stack);
	if (*stack->next == biggest)
		rra(stack);
	if (*stack->value > *stack->next->value)
		sa(stack);
}
