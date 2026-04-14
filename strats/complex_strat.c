#include "../push_swap.h"

void	quick_sort(t_list **stack_a, t_list **stack_b, t_operations *op, int size, bool bench);
static int	find_max_val(t_list *stack, int size);
static int	find_min_val(t_list	*stack, int size);

void	complex_strat(t_list **stack_a, t_list **stack_b,
				t_operations *op, t_flags *flags)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	flags->strategy = COMPLEX;
	ft_printf("Inside complex strat\n");
	quick_sort(stack_a, stack_b, op, stack_size, flags->bench);
}

void	quick_sort(t_list **stack_a, t_list **stack_b, t_operations *op, int size, bool bench)
{
	int	pivot1;
	int	pivot2;
	int	min;
	int	max;
	int	counter;

	counter = 0;
	min = find_min_val(*stack_a, size);
	max = find_max_val(*stack_a, size);
	pivot1 = (min + (max - min) / 3);
	pivot2 = (min + 2 * (max - min) / 3);
	ft_printf("min: %i // max: %i\n", min, max);
	ft_printf("1: %i // 2: %i\n", pivot1, pivot2);
	while (counter++ < size)
	{
		if (*(int *)(*stack_a)->content <= pivot1)
		{
			pb(stack_b, stack_a, op, bench);
			rb(stack_b, op, bench);
		}
		else if (*(int *)(*stack_a)->content <= pivot2)
			pb(stack_b, stack_a, op, bench);
		else if (*(int *)(*stack_a)->content > pivot2)
			ra(stack_a, op, bench);
	}
}

// static int	find_max_val(t_list *stack, int size)
// {
// 	int	max;

// 	max = *(int *)stack->content;
// 	while (size-- > 0 && !stack)
// 	{
// 		if (*(int *)stack->content > max)
// 			max = *(int *)stack->content;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

static int	find_max_val(t_list	*stack, int size)
{
	int		max;

	max = *(int *)stack->content;
	while (stack != NULL && size-- > 0)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

static int	find_min_val(t_list	*stack, int size)
{
	int		min;

	min = *(int *)stack->content;
	while (stack != NULL && size-- > 0)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

// static int	find_min_val(t_list *stack, int size)
// {
// 	int	min;

// 	min = *(int *)stack->content;
// 	while (size-- > 0 && !stack)
// 	{
// 		if (*(int *)stack->content < min)
// 			min = *(int *)stack->content;
// 		stack = stack->content;
// 	}
// 	return (min);
//}
/*
	pivot1 = 4
	pivot2 = 8

	size = 0
	stackA = [ 12 11 9 10 ]
	stackB = [ 5 6 *8 7 *4 3 2 1 ]
 */