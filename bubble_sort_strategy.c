/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:53:04 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/16 10:53:17 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_strategy(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	(void)b;
	if (is_sorted(a))
		return ;
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (a->top->value > a->top->next->value)
				sa(a);
			ra(a);
			j++;
		}
		rra(a);
		i++;
	}
}
