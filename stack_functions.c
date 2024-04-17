/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:20 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 16:57:28 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_append_node(t_item **stack, int value, int index)
{
	t_item	*item;
	t_item	*head;

	head = *stack;
	item = (t_item *)malloc(sizeof(t_item));
	if (!item)
		return ;
	item->value = value;
	item->index = index;
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

int	ft_exist_value(t_item **stack, int arg)
{
	t_item	*item;

	item = *stack;
	while (item)
	{
		if (arg == item->value)
			return (perror("Error\nDUPLICATED VALUE\n"), 1);
		item = item->next;
	}
	return (0);
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

int	ft_fill_stack(t_item **a, char **argv, int argv_in_heap)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_is_not_number(argv[i]) || ft_exist_value(a, ft_atoi(argv[i])))
		{
			ft_free_stack(a);
			if (argv_in_heap)
				ft_free_array(argv);
			exit(EXIT_FAILURE);
		}
		ft_append_node(a, ft_atoi(argv[i]), i);
		++i;
	}
	if (argv_in_heap)
		ft_free_array(argv);
	return (0);
}
