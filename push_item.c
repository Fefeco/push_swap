/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 15:23:33 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ft_calc_cost(t_item **stack_from, t_item **stack_to)
{
	t_item	*head;

	head = *stack_from;
	while (*stack_from)
	{

	}
}

void	ft_push_item(t_item **stack_from, t_item **stack_to)
{
	t_item	*cheapest;

	ft_calc_cost(t_item stack_from, t_item stack_to);
	cheapest = ft_get_node(*stack_from);
}
