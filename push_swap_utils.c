/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 13:28:26 by fcarranz         ###   ########.fr       */
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
			return (perror("Valor, repetido\n"), 1);
		item = item->next;
	}
	return (0);
}

int	ft_fill_stack(t_item **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_not_number(argv[i]) || ft_exist_value(a, ft_atoi(argv[i])))
			return (ft_free_stack(a), 1);
		ft_append_node(a, ft_atoi(argv[i]));
		++i;
	}
	ft_free_stack(a);
	return (0);
}
