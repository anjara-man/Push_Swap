/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:11:30 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/16 12:15:43 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->data[a->size] = b->data[b->size - 1];
	a->size++;
	b->size--;
	// ft_putstr("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	b->data[b->size] = a->data[a->size - 1];
	b->size++;
	a->size--;
	// ft_putstr("pb\n");
}
