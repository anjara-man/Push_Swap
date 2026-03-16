/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/16 11:52:57 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

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

void	print_stack(t_stack *stack, char *name)
{
	int	i;

	i = stack->size - 1;
	printf("%s: ", name);
	while (i >= 0)
	{
		printf("%d ", stack->data[i]);
		i--;
	}
	printf("(size: %d)\n", stack->size);
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

int main()
{
	t_stack a, b;
	int test_values[] = {3, 1, 4, 2, 5};

	init_stack(&a, test_values, 5);
	b.size = 0;
	b.data = (int *)malloc(sizeof(int) * 10);
	b.top = NULL;

	printf("Initial state:\n");
	print_stack(&a, "Stack A");
	print_stack(&b, "Stack B");
	printf("Is A sorted: %d\n", is_sorted(&a));
	printf("Disorder metric A: %f\n", disorder_metric(&a));

	printf("\nTesting operations:\n");

	printf("Before sa:\n");
	print_stack(&a, "A");
	sa(&a);
	printf("After sa:\n");
	print_stack(&a, "A");

	pa(&a, &b);
	printf("After pa (b empty):\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	pb(&a, &b);
	pb(&a, &b);
	printf("After pb twice:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	ra(&a);
	printf("After ra:\n");
	print_stack(&a, "A");

	rra(&a);
	printf("After rra:\n");
	print_stack(&a, "A");

	sb(&b);
	printf("After sb:\n");
	print_stack(&b, "B");

	ss(&a, &b);
	printf("After ss:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	rb(&b);
	printf("After rb:\n");
	print_stack(&b, "B");
	rr(&a, &b);
	printf("After rr:\n");
	print_stack(&a, "A");

	print_stack(&b, "B");

	rrb(&b);
	printf("After rrb:\n");
	print_stack(&b, "B");

	rrr(&a, &b);
	printf("After rrr:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	free_stack(&a);
	free_stack(&b);
	int reset_values[] = {5, 3, 1, 4, 2};
	init_stack(&a, reset_values, 5);
	b.size = 0;
	b.data = (int *)malloc(sizeof(int) * 10);
	b.top = NULL;

	printf("\nTesting strategies:\n");
	printf("Before simple_strategy:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	simple_strategy(&a, &b);
	printf("After simple_strategy:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	printf("Is A sorted: %d\n", is_sorted(&a));

	free_stack(&a);
	free_stack(&b);
	init_stack(&a, reset_values, 5);
	b.size = 0;
	b.data = (int *)malloc(sizeof(int) * 10);
	b.top = NULL;

	printf("\nBefore bubble_sort_strategy:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	bubble_sort_strategy(&a, &b);
	printf("After bubble_sort_strategy:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	printf("Is A sorted: %d\n", is_sorted(&a));

	free_stack(&a);
	free_stack(&b);

	return 0;
}