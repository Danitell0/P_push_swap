#include "../push_swap.h"

void	quick_sort(t_list **stack_a, t_list **stack_b, t_operations *op, int size, bool bench);
static int	find_max_val(t_list *stack, int size);
static int	find_min_val(t_list	*stack, int size);
void	sort_chunk(t_list **src, t_list **dest, t_operations *op, bool bench);

void	complex_strat(t_list **stack_a, t_list **stack_b,
				t_operations *op, t_flags *flags)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	flags->strategy = COMPLEX;
	ft_printf("Inside complex strat\n");
	quick_sort(stack_a, stack_b, op, stack_size, flags->bench);
}

void	quick_sort(t_list **src, t_list **dest, t_operations *op, int size, bool bench)
{
	int	pivot1;
	int	pivot2;
	int	min;
	int	max;
	int	counter;
	int	size_top;
	int	size_middle;
	int	size_bottom;

	size_top = 0;
	size_middle = 0;
	size_bottom = 0;
	counter = 0;
	min = find_min_val(*src, size);
	max = find_max_val(*src, size);
	pivot1 = (min + (max - min) / 3);
	pivot2 = (min + 2 * (max - min) / 3);
	if (size <= 3 || pivot1 == pivot2)
	{
		sort_chunk(src, dest, op, bench);
		return ;
	}
	while (counter++ < size)
	{
		if (*(int *)(*src)->content <= pivot1)
		{
			pb(dest, src, op, bench);
			rb(dest, op, bench);
			size_bottom += 1;
		}
		else if (*(int *)(*src)->content <= pivot2)
		{
			pb(dest, src, op, bench);
			size_middle += 1;
		}
		else if (*(int *)(*src)->content > pivot2)
		{
			ra(src, op, bench);
			size_top += 1;
		}
	}
	quick_sort(src, dest, op, size_top, bench);
	quick_sort(dest, src, op, size_middle, bench);
	quick_sort(dest, src, op, size_bottom, bench);
}

void	sort_chunk(t_list **src, t_list **dest, t_operations *op, bool bench)
{
	int	min_pos_index;
	int	stack_size;

	while (*src != NULL)
	{
		stack_size = ft_lstsize(*src);
		min_pos_index = find_min(*src);
		if (min_pos_index < stack_size / 2)
			while (min_pos_index--)
				ra(src, op, bench);
		else if (min_pos_index != 0)
		{
			min_pos_index = stack_size - min_pos_index;
			while (min_pos_index--)
				rra(src, op, bench);
		}
		pa(dest, src, op, bench);
	}
	while (*src != NULL)
		pb(dest, src, op, bench);
}

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
