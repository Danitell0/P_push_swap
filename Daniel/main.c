#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_list(t_list *stack, char *name)
{
    printf("Stack %s: ", name);
    while (stack)
    {
        printf("[%d] ", *(int *)stack->content);
        stack = stack->next;
    }
    printf("\n");
}

int	*new_int(int value)
{
    int	*n;

    n = malloc(sizeof(int));
    if (!n)
        return (NULL);
    *n = value;
    return (n);
}

void	free_stack(t_list **stack)
{
    t_list	*tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free((*stack)->content);
        free(*stack);
        *stack = tmp;
    }
}

// --- Main ---

int	main(int argc, char **argv)
{
    t_list	*a;
    t_list	*b;
    int		i;
    int		*n;

    a = NULL;
    b = NULL;
    i = 1;
    print_list(a, "A");
    print_list(b, "B");
    while (i < argc)
    {
        n = new_int(ft_atoi(argv[i]));
        ft_lstadd_back(&a, ft_lstnew(n));
        i++;
    }
    simple_strat(&a, &b);

    print_list(a, "A");
    print_list(b, "B");
    // free_stack(&a);
	// free_stack(&b);
    return (0);
}