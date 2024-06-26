/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:20 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/08 11:54:11 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_append_node(t_item **stack, int value, int index)
{
	t_item	*item;
	t_item	*head;

	head = *stack;
	item = (t_item *)malloc(sizeof(t_item));
	if (!item)
		return ;
	item->value = value;
	item->index = index;
	item->cheapest = false;
	item->next = NULL;
	if (!*stack)
	{
		*stack = item;
		(*stack)->prev = NULL;
		return ;
	}
	else
		while ((*stack)->next)
			*stack = (*stack)->next;
	(*stack)->next = item;
	(*stack)->next->prev = *stack;
	*stack = head;
}

static int	ft_exist_value(t_item **stack, int arg)
{
	t_item	*item;

	item = *stack;
	while (item)
	{
		if (arg == item->value)
			return (write(STDERR_FILENO, "Error\n", 6), 1);
		item = item->next;
	}
	return (0);
}

static int	ft_is_not_number(char *str)
{
	if (!*str)
		return (1);
	if (*str == '-')
		++str;
	if (!*str)
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	while (*str)
		if (!ft_strchr(NUMBERS, *str++))
			return (write(STDERR_FILENO, "Error\n", 6), 1);
	return (0);
}

static int	ft_get_number(char *str, int *value)
{
	long	nb;

	nb = ft_atol(str);
	if ((nb > INT_MAX || nb < INT_MIN) || ft_len_char_nb(str) > 11)
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	*value = (int)nb;
	return (0);
}

void	ft_fill_stack(t_item **a, char **argv, int argv_in_heap)
{
	int	i;
	int	error_flag;
	int	value;

	i = 0;
	while (argv[i])
	{
		error_flag = 1;
		if (ft_is_not_number(argv[i]) || ft_get_number(argv[i], &value)
			|| ft_exist_value(a, value))
			break ;
		ft_append_node(a, value, i);
		++i;
		error_flag = 0;
	}
	if (argv_in_heap)
		ft_free_array(argv);
	if (error_flag)
	{
		ft_free_stack(a);
		exit(EXIT_FAILURE);
	}
}
