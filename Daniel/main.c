#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

// --- Helpers for testing ---

t_stack	*new_node(int value)
{
    t_stack	*node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->content = value;
    node->next = NULL;
    return (node);
}

void	push_top(t_stack **stack, int value)
{
    t_stack	*node;

    node = new_node(value);
    if (!node)
        return ;
    node->next = *stack;
    *stack = node;
}

void	print_stack(t_stack *stack, char *name)
{
    printf("Stack %s: ", name);
    while (stack)
    {
        printf("[%d] ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

void	free_stack(t_stack **stack)
{
    t_stack	*tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

// --- Main ---

int	main(void)
{
    t_stack	*a;
	t_stack *b;

    a = NULL;
	b = NULL; 
    // Build stack a: top -> 1 -> 2 -> 3
    push_top(&a, 3);
    push_top(&a, 2);
    push_top(&a, 1);

    printf("=== Initial state ===\n");
    print_stack(a, "a");
	print_stack(b, "b");

    sa(&a);
    print_stack(a, "a");
	print_stack(b, "b");

	sa(&a);
    print_stack(a, "a");
	print_stack(b, "b");

	pa(&a, &b);
	print_stack(a, "a");
	print_stack(b, "b");

    free_stack(&a);
	free_stack(&b);
    return (0);
}