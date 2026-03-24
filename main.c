#include "push_swap.h"
#include <stdio.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);

	stack.top = NULL;
	stack.size = 0;

	printf("Lancement du parsing...\n");
	parse_int_input(argc, argv, &stack);

	print_stack(&stack);

	return (0);
}
