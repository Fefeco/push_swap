/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:05:01 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/15 12:12:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_item
{
	int		index;
	int		value;
	int		cost;
	bool	cheapest;
	t_item	*prev;
	t_item	*next;
}	t_item;

typedef struct	s_stack
{
	t_item	**item;
}	t_stack;
