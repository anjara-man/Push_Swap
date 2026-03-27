#include "push_swap.h"

// static int	stack_size(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack)
// 		return (0);
// 	while (stack)
// 	{
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (i);
// }
// float	compute_disorder(t_stack *a)
// {
// 	int		mistakes;
// 	int		total_pairs;
// 	// int		size;

// 	if (!a)
// 		return (0.0);
// 	mistakes = 0;
// 	total_pairs = 0;
// 	// size = stack_size(a);
// 	while (a->next)
// 	{
// 		if (a->value > a->next->value)
// 			mistakes++;
// 		a = a->next;
// 		total_pairs++;
// 	}
// 	return ((float)mistakes / total_pairs);
// }

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*curr; // Utilisation d'un pointeur temporaire

	if (!a || !a->next) // Sécurité : si pile vide ou un seul élément
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	curr = a;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			mistakes++;
		total_pairs++;
		curr = curr->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
