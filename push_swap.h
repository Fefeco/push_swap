/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:05:01 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/17 14:15:24 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#define NUMBERS "0123456789"

typedef struct	s_item
{
	int				index;
	int				value;
	int				cost;
	bool			cheapest;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

int		ft_is_num(char *str);
int		ft_fill_stack(t_item **a, char **argv);
void	ft_free_stack(t_item **stack);
int		ft_exist_value(t_item **stack, int arg);
int		ft_is_not_number(char *str);
int		ft_is_ordered(t_item **stack);
