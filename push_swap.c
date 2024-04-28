/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/28 13:34:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_item **stack)
{
	t_item	*next_item;

	if (!stack)
		return ;
	while (*stack)
	{
		next_item = (*stack)->next;
		free (*stack);
		*stack = next_item;
	}
	stack = NULL;
}

int	main(int argc, char **argv)
{
	t_item	*a;
	t_item	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1])
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_fill_stack(&a, argv, 1);
	}
	else
		ft_fill_stack(&a, ++argv, 0);
	if (!ft_is_ordered(&a) || ft_stack_size(a) == 1)
		return (ft_free_stack(&a), 1);
	ft_order(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
