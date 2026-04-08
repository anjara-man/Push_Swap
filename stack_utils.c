/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:19:03 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/02 09:15:02 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// void	init_stack(t_stack *stack, int *values, int count)
// {
// 	int		i;
// 	t_node	*node;

// 	stack->size = count;
// 	stack->data = (int *)malloc(sizeof(int) * count * 2);
// 	if (!stack->data)
// 		return ;
// 	stack->top = NULL;
// 	i = 0;
// 	while (i < count)
// 	{
// 		stack->data[i] = values[i];
// 		node = new_node(values[i]);
// 		if (!stack->top)
// 		{
// 			stack->top = node;
// 		}
// 		else
// 		{
// 			node->next = stack->top;
// 			stack->top = node;
// 		}
// 		i++;
// 	}
// }
void	init_stack(t_stack **stack, int *values, int count)
{
	int	i;

	if (!stack || !values)
		return ;
	*stack = NULL;
	i = 0;
	while (i < count)
	{
		append_node(stack, values[i]);
		i++;
	}
}

// void	print_stack(t_stack *stack)
// {
// 	t_node	*curr;

// 	curr = stack->top;
// 	ft_printf("État de la pile : ");
// 	while (curr)
// 	{
// 		ft_printf("%d ", curr->value);
// 		curr = curr->next;
// 	}
// 	ft_printf("\n");
// }
void	print_stack(t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	ft_printf("État de la pile : ");
	if (!curr)
	{
		ft_printf("(vide)\n");
		return ;
	}
	while (curr)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

// void	free_stack(t_stack *stack)
// {
// 	t_node	*current;
// 	t_node	*temp;

// 	current = stack->top;
// 	while (current)
// 	{
// 		temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// 	free(stack->data);
// }
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
