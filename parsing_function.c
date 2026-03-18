/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:55:05 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/18 13:46:26 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	push(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
}

void	split_and_loop(char *input, t_stack *stack)
{
	char	**tokens;
	int		i;
	int		value;

	tokens = ft_split(input, ' ');
	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		value = ft_atoi(tokens[i]);
		if (value < -2147483648 || value > 2147483647)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		push(stack, value);
		i++;
	}
	free_tokens(tokens);
}
