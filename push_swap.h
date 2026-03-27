/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:47:56 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/25 12:50:51 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		*data;
}	t_stack;

// typedef struct s_stack
// {
// 	int				value;
// 	int				index;
// 	int				push_cost;
// 	bool			above_median;
// 	bool			cheap_move;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// 	struct s_stack	*target_node;
// }	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	simple_strategy(t_stack *a, t_stack *b);
void	bubble_sort_strategy(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
float	disorder_metric(t_stack *stack);
void	parse_int_input(int argc, char **argv, t_stack *stack);
t_node	*new_node(int value);
void	free_tokens(char **tokens);
void	push(t_stack *stack, int value);
int		check_duplicates(t_stack *stack);
void	init_stack(t_stack *stack, int *values, int count);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	print_error();
int		is_number(char *str);
void	split_and_loop(char *str, t_stack *stack);

#endif