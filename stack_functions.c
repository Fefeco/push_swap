/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:20 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 13:56:27 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_append_node(t_item **stack, int value)
{
	t_item	*item;
	t_item	*head;

	head = *stack;
	item = (t_item *)malloc(sizeof(t_item));
	if (!item)
		return ;
	item->value = value;
	item->next = NULL;
	if (!*stack)
	{
		*stack = item;
		return ;
	}
	else
		while ((*stack)->next)
			*stack = (*stack)->next;
	(*stack)->next = item;
	*stack = head;
}

int	ft_fill_stack(t_item **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_not_number(argv[i]) || ft_exist_value(a, ft_atoi(argv[i])))
		{
			ft_free_stack(a);
			exit(EXIT_FAILURE);
		}
		ft_append_node(a, ft_atoi(argv[i]));
		++i;
	}
	ft_free_stack(a);
	return (0);
}
