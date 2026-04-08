#include "push_swap.h"

static void	swap_cmd(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	sa(t_stack **a)
{
	swap_cmd(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_cmd(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_cmd(a);
	swap_cmd(b);
	write(1, "ss\n", 3);
}