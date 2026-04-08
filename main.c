#include "push_swap.h"
#include <stdio.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*flag;

	if (argc < 2)
		return (0);

	stack_a = NULL;
	stack_b = NULL;
	(void)flag;

	printf("Lancement du parsing...\n");
	parse_all_input(argc, argv, &stack_a);
	print_stack(stack_a);
	free_stack(&stack_a);

	return (0);
}
