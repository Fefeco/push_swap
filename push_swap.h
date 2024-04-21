/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:05:01 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/21 12:34:33 by fcarranz         ###   ########.fr       */
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
void	ft_fill_stack(t_item **a, char **argv, int argv_in_heap);
void	ft_free_stack(t_item **stack);
int		ft_exist_value(t_item **stack, int arg);
int		ft_is_not_number(char *str);
int		ft_is_ordered(t_item **stack);
void	ft_free_array(char **array);
size_t	ft_stack_size(t_item *stack);
void	ft_order(t_item **stack);
void	set_index(t_item **stack);
void	ra(t_item **stack);
void	rra(t_item **stack);
void	sa(t_item **stack);
void	ft_print_more_info(t_item **stack);	///PRUEBA
