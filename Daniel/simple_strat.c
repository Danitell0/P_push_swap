// SELECTION SORT STRATEGY

#include "push_swap.h"

int	find_min(t_list	*stack)
{
	t_list	*min_pos;
	int		node_pos;

	node_pos = 0;
	min_pos = stack;
	while (stack != NULL)
	{
		if ((int *)stack->content <= (int *)min_pos->content)
		{
			ft_printf("X");
			min_pos = stack;
			node_pos += 1;
		}
		*stack = *stack->next;
	}
	return (node_pos);
}
