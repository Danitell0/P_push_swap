#include "push_swap.h"

static void push_cmd(t_stack **src, t_stack **dst)
{
    t_stack *temp;

    if (!src || !*src)
        return ;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}

void    pa(t_stack **a, t_stack **b)
{
    push_cmd(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_stack **b, t_stack **a)
{
    push_cmd(a, b);
    write(1, "pb\n", 3);
}
