/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:05:01 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/28 12:59:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#define NUMBERS "0123456789"
#define BIGGEST 'B'
#define SMALLEST 'S'
#define CHEAPEST 'C'
#define PUSH_TO_A 'a'
#define PUSH_TO_B 'b'

typedef struct s_item
{
	int				index;
	int				len_to_end;
	int				value;
	int				cost;
	bool			cheapest;
	bool			under_middle;
	struct s_item	*target;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

void	ft_fill_stack(t_item **a, char **argv, int argv_in_heap);
t_item	*ft_get_node(t_item *stack, char target);
void	set_index(t_item **stack_a, t_item **stack_b);
void	ft_free_array(char **array);
int		ft_is_ordered(t_item **stack);
void	ft_free_stack(t_item **stack);
size_t	ft_stack_size(t_item *stack);
void	ft_order(t_item **stack_a, t_item **stack_b);
void	sx(t_item **stack, char push_to);
void	rx(t_item **stack, char push_to);
void	rrx(t_item **stack, char push_to);
void	rr(t_item **stack, t_item **stack_b);
void	rrr(t_item **stack, t_item **stack_b);
void	px(t_item **stack_from, t_item **stack_to, char stk_id);
void	ft_push_item(t_item **stack_from, t_item **stack_to, char push_to);
void	ft_set_mid(t_item *stk_from, t_item *stk_to, int len_from, int len_to);
void	ft_find_target_on_a(t_item *item, t_item *stack_to);
void	ft_find_target_on_b(t_item *item, t_item *stack_to);
void	ft_sort_stack(t_item **stack, char stk_id);
int		ft_print_more_info(t_item **stack);	///PRUEBA
int		ft_print_node_info(t_item **stack);	///PRUEBA
