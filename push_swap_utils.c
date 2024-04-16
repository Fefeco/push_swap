/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:49 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/16 13:47:16 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_append_node(t_item **stack, int value)
{
	t_item	*item;
	t_item	*tmp;

	tmp = *stack;
	item = (t_item *)malloc(sizeof(t_item));
	if (!item)
		return ;
	item->value = value;
	item->next = NULL;
	if (!tmp)
	{
		tmp = item;
		return ;
	}
	else
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = item;
}



int	ft_is_num(char *str)
{
	if (!*str)
		return (1);
	if (*str == '-')
		++str;
	while (*str)
		if (!ft_strchr(NUMS, *str++))
			return (perror("Error\nINVALID CHAR"), 1);
	return (0);
}

void	ft_free_stack(t_item *stack)
{
	t_item	*next_item;

	if (!stack)
		return ;
	while (stack->next)
	{
		next_item = stack->next;
//		ft_printf("NEXT ITEM con value %d\n", next_item->value);
//		ft_printf("LIBERO NODO con value %d\n", stack->value);
		free (stack);
		stack = next_item;
//		ft_printf("LLego\n");
	}
	free (stack);
	stack = NULL;
}

int	ft_fill_stack(t_item *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_num(argv[i]))
			return (ft_free_stack(a), 1);
		ft_append_node(&a, ft_atoi(argv[i]));
		++i;
	}
	ft_free_stack(a);
	return (0);
}
