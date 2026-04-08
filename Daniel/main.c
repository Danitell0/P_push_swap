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

void	free_stack(t_list **stack)
{
    t_list	*tmp;

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
    t_list	*a;
	// t_list  *b;
    float   disorder;
    int      value1 = 6;
    int      value2 = 4;
    int      value3 = 2;
    int      value4 = 8;
    int      value5 = 14;
    int      value6 = 258;
    int      value7 = 1;
    int      value8 = 100;
    int      value9 = 80;



    a = NULL;
	// b = NULL; 

    ft_lstadd_front(&a, ft_lstnew(&value1));
    ft_lstadd_front(&a, ft_lstnew(&value2));
    ft_lstadd_front(&a, ft_lstnew(&value3));
    ft_lstadd_front(&a, ft_lstnew(&value4));
    ft_lstadd_front(&a, ft_lstnew(&value5));
    ft_lstadd_front(&a, ft_lstnew(&value6));
    ft_lstadd_front(&a, ft_lstnew(&value7));
    ft_lstadd_front(&a, ft_lstnew(&value8));
    ft_lstadd_front(&a, ft_lstnew(&value9));

    disorder = compute_disorder(a);

    printf("%.1f\n", disorder);
    // print_list(a, "a");
	// print_list(b, "b");

    // sa(&a);
    // print_list(a, "a");
	// print_list(b, "b");

	// sa(&a);
    // print_list(a, "a");
	// print_list(b, "b");

    // rra(&a);
	// print_list(a, "a");
	// print_list(b, "b");

    // free_stack(&a);
	// free_stack(&b);
    return (0);
}