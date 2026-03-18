/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:17:08 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/16 12:18:11 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = temp;
	// ft_putstr("rra\n");
}

void	rrb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[0];
	memmove(b->data, b->data + 1, sizeof(int) * (b->size - 1));
	b->data[b->size - 1] = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	// ft_putstr("rrr\n");
}
