#include "../push_swap.h"

void	quick_sort(t_list **a, t_list **b, t_operations *op, int size);
static int	find_max_val(t_list *stack, int size);
static int	find_min_val(t_list *stack, int size);

void	complex_strat(t_list **stack_a, t_list **stack_b,
				t_operations *op, t_flags *flags)
{
	flags->strategy = COMPLEX;
	ft_printf("Inside complex strat\n");
	quick_sort(stack_a, stack_b, op, ft_lstsize(stack_a));
}

void	quick_sort(t_list **a, t_list **b, t_operations *op, int size)
{
	int	pivot1;
	int	pivot2;
	int	min;
	int	max;

	min = find_min_val(*a, size);
	max = find_max_val(*a, size);
	pivot1 = min + (max - min) / 3;
	pivot2 = min + 2 * (max - min) / 3;
}

static int	find_max_val(t_list *stack, int size)
{
	int	max;

	max = *(int *)stack->content;
	while (size-- > 0 && !stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

static int	find_min_val(t_list *stack, int size)
{
	int	min;

	min = *(int *)stack->content;
	while (size-- > 0 && !stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->content;
	}
	return (min);
}
