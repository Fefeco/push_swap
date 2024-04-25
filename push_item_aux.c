/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:57:37 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/25 19:26:19 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_mid(t_item *stk_from, t_item *stk_to, int len_from, int len_to)
{
	while (stk_from)
	{
		stk_from->len_to_end = len_from - stk_from->index;
		stk_from = stk_from->next;
	}
	while (stk_to)
	{
		stk_to->len_to_end = len_to - stk_to->index;
		stk_to = stk_to->next;
	}
}
