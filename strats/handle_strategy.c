#include "../push_swap.h"
#include <stdio.h>

static float	compute_disorder(t_list *stack_a);
static void	bench(t_flags flags, t_operations op, float disorder);
static void	print_disorder(float disorder);

/**
 * @brief  Selects and dispatches a sorting strategy based on flags 
 * 		   or disorder score.
 *
 * @details  If `flags.strategy` is 0 (ADAPTIVE), computes the 
 * 			 disorder score of `stack_a` and selects a strategy 
 * 			 automatically. If a strategy was explicitly
 *           set via flags, dispatches directly to the corresponding
 * 			 function without computing disorder.
 */
void	select_strategy(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	float			disorder;
	t_operations	operations;

	disorder = compute_disorder(*stack_a);
	ft_memset(&operations, 0, sizeof(t_operations));
	if (flags->strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			simple_strat(stack_a, stack_b, &operations, flags);
		else if (disorder >= 0.2 && disorder < 0.5)
			medium_strat(stack_a, stack_b, &operations, flags);
		else
			complex_strat(stack_a, stack_b, &operations, flags);
	}
	else
	{
		if (flags->strategy == SIMPLE)
			simple_strat(stack_a, stack_b, &operations, flags);
		else if (flags->strategy == MEDIUM)
			medium_strat(stack_a, stack_b, &operations, flags);
		else if (flags->strategy == COMPLEX)
			complex_strat(stack_a, stack_b, &operations, flags);
	}
	if (flags->strategy == 1)
		bench(*flags, operations, disorder);
}

/**
 * @brief  Computes the disorder ratio of a linked list of integers.
 *
 * @details  Counts all pairs (i, j) where i appears before j in the 
 * 			 list but holds a greater value. The disorder score is 
 * 			 the ratio of inversions to total pairs examined, 
 * 			 producing a value in [0.0, 1.0].
 * 
 * @return float — Inversion ratio in the range [0.0, 1.0].
 *                 0.0 indicates a fully sorted list or NULL/single-node input.
 *                 1.0 indicates a fully reversed list.
 */
static float	compute_disorder(t_list *stack_a)
{
	float		mistakes;
	float		total_pairs;
	t_list		*current;
	t_list		*next;

	if (!stack_a)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack_a;
	while (current->next != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (*(int *)current->content > *(int *)next->content)
				mistakes += 1;
			next = next->next;
			total_pairs += 1;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

#include <stdio.h>

static void	bench(t_flags flags, t_operations op, float disorder)
{
	char	*strats[4];
	char	*bigO[3];
	int	total_operations;

	strats[0] = "Adaptive";
	strats[1] = "Simple";
	strats[2] = "Medium";
	strats[3] = "Complex";
	bigO[0] =  "O(n^2)";
	bigO[1] =  "O(n√n)";
	bigO[2] =  "O(nlogn)";
	printf("Disorder: %.2f\n", disorder);
	sum_operations(op, &total_operations);
//	ft_printf("[bench] disorder: %d.%.2d%%\n", (int)(disorder * 100), (int)(disorder * 10000) % 100);
	ft_printf("[bench] disorder: ");
	print_disorder(disorder);
	ft_printf("[bench] strategy: %s / %s\n", strats[flags.strategy], bigO[flags.strategy - 1]);
	ft_printf("[bench] total_ops: %d\n", total_operations);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  ", op.sa, op.sb, op.ss);
	ft_printf("pa: %d  pb: %d\n", op.pa, op.pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  ", op.ra, op.rb, op.rr);
	ft_printf("rra: %d  rrb: %d  rrr: %d\n", op.rra, op.rrb, op.rrr);
}

static void	print_disorder(float disorder)
{
	int		percentage;
	char	c;

	if (disorder == 1)
	{
		write(1, "1.00", 4);
		return ;
	}
	percentage = (int)(disorder * 100 + 0.5); // 0.5 rounds the number
	write(1, "0", 1);
	write(1, ".", 1);
	c = '0' + percentage / 10;
	write(1, &c, 1);
	c = '0' + percentage % 10;
	write(1, &c, 1);
	write(1, "%\n", 2);
}
