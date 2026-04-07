#include "pushswap.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_stack *stack_a;

	stack_a = NULL;
	push(&stack_a, 7);
	push(&stack_a, 6);
	push(&stack_a, 5);
	push(&stack_a, 4);
	push(&stack_a, 3);
	push(&stack_a, 2);
	push(&stack_a, 1);

	while (stack_a != NULL)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
}