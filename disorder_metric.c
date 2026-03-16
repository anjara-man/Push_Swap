/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:04:26 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/16 12:10:47 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metric(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (stack->size <= 1)
		return (0.0);
	count = 0;
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			count++;
		current = current->next;
	}
	return ((float)count / (stack->size - 1));
}
