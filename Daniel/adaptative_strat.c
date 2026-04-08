#include "push_swap.h"

/**
 * function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
 */

float compute_disorder(t_list *stack)
{
	float		mistakes;
	float		total_pairs;
	t_list		*i;
	t_list		*j;

	if (!stack)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (*(int *)i->content > *(int *)j->content)
				mistakes += 1;
			j = j->next;
			total_pairs += 1;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
void	algorithm_checker(t_list **a, t_list **b)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if(disorder < 0.2)
		//LOW DISORDER(a, b);
	else if (0.2 < disorder && disorder < 0.5)
		//MEDIUM DISORDER(a, b);
	else if (disorder > .5)
		//HIGH DISORDER(a, b);
}