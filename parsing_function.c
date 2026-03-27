/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:55:05 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/25 12:55:26 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	split_and_loop(char *input, t_stack *stack)
{
	char	**tokens;
	int		i;
	long	value;

	tokens = ft_split(input, ' ');
	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		if (!is_number(tokens[i]))
			print_error();
		value = ft_atoi(tokens[i]);
		if (value < -2147483648 || value > 2147483647)
			print_error();
		push(stack, value);
		if (check_duplicates(stack) == 0)
			print_error();
		i++;
	}
	free_tokens(tokens);
}

void	parse_int_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			split_and_loop(argv[i], stack);
		else
		{
			if (!is_number(argv[i]))
				print_error();
			value = ft_atoi(argv[i]);
			if (value < -2147483648 || value > 2147483647)
				print_error();
			push(stack, value);
			if (check_duplicates(stack) == 0)
				print_error();
		}
		i++;
	}
}
