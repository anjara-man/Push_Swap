/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:19:03 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/20 14:53:31 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	init_stack(t_stack *stack, int *values, int count)
{
	int		i;
	t_node	*node;

	stack->size = count;
	stack->data = (int *)malloc(sizeof(int) * count * 2);
	if (!stack->data)
		return ;
	stack->top = NULL;
	i = 0;
	while (i < count)
	{
		stack->data[i] = values[i];
		node = new_node(values[i]);
		if (!stack->top)
		{
			stack->top = node;
		}
		else
		{
			node->next = stack->top;
			stack->top = node;
		}
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	ft_printf("État de la pile : ");
	while (curr)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack->data);
}
