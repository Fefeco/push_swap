/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 13:56:38 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_not_number(char *str)
{
	if (!*str)
		return (1);
	if (*str == '-')
		++str;
	while (*str)
		if (!ft_strchr(NUMBERS, *str++))
			return (perror("Error\nINVALID CHAR"), 1);
	return (0);
}

void	ft_free_stack(t_item **stack)
{
	t_item	*next_item;

	if (!stack)
		return ;
	while ((*stack)->next)
	{
		next_item = (*stack)->next;
		free (*stack);
		*stack = next_item;
	}
	free (*stack);
	stack = NULL;
}

int	ft_exist_value(t_item **stack, int arg)
{
	t_item	*item;

	item = *stack;
	while (item)
	{
		if (arg == item->value)
			return (perror("Error\nValor duplicado\n"), 1);
		item = item->next;
	}
	return (0);
}
