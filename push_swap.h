/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:05:01 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/16 12:36:01 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#define NUMS "0123456789"

typedef struct	s_item
{
	int				index;
	int				value;
	int				cost;
	bool			cheapest;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

typedef struct	s_stack
{
	t_item	**item;
}	t_stack;

int	ft_is_num(char *str);
int	ft_fill_stack(t_item *a, char **argv);
