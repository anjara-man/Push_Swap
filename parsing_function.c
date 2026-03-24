/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:55:05 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/23 10:30:56 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	parse_int_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	value;

	if (argc == 2)
		split_and_loop(argv[1], stack);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strchr(argv[i], ' '))
				split_and_loop(argv[i], stack);
			else
			{
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
}
