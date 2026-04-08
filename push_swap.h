/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:47:56 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/08 10:14:24 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheap_move;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;

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
void	parse_int_input(char **argv, t_stack **stack, int start, int end);
t_stack	*new_node(int value);
void	free_tokens(char **tokens);
void	append_node(t_stack **stack, int value);
int		check_duplicates(t_stack *stack);
void	init_stack(t_stack **stack, int *values, int count);
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);
void	print_error(t_stack **stack);
int		is_number(char *str);
void	split_and_loop(char *str, t_stack **stack);
int		check_flag(const char *str);
int		is_flag(const char *str);
int		check_duplicate_flag(char **argv, int argc);
void	parse_all_input(int argc, char **argv, t_stack **stack);
int		check_flag_position(int argc, char **argv);
int		check_strat_flag_presence(int argc, char **argv);
int		check_bench_flag(const char *str);
int		is_bench(const char *str);
int		check_duplicate_bench_flag(char **argv, int argc);
int		valide_flag(int argc, char **argv, t_stack **stack);
int		check_bench_flag_position(int argc, char **argv);
int		check_flag_bench_presence(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);

#endif